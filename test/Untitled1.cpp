#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include <iostream>

typedef HANDLE semaphore;
semaphore g_semBuffer, g_semGlass, g_mutex;

#define P(S) WaitForSingleObject(S, INFINITE)
#define V(S) ReleaseSemaphore(S, 1, NULL)
#define rate 1000
#define CONSUMER_NUM 4
#define PRODUCER_NUM 4
#define BUFFER_NUM 4

char *thing[4] = {"glass1", "glass2", "glass3", "glass4"};
struct Buffer {
    int product[BUFFER_NUM];
    int front, rear;
} g_buf;

DWORD WINAPI Rabbit(LPVOID para) {
    int i = *(int *)para;
    int ptr;
    Sleep(1800);
    while (1) {
        printf("%03d小白兔:我饿了........!\n", i);
        P(g_semGlass);
        P(g_mutex);
        ptr = g_buf.front;
        g_buf.front = (g_buf.front + 1) % BUFFER_NUM;
        V(g_mutex);
        Sleep(rate * rand() % 10 + 1800);
        printf("%03d小白兔:我吃了buf[%d] = %s的草\n", i, ptr, thing[g_buf.product[ptr]]);
        V(g_semBuffer);
    }
    return 0;
}

DWORD WINAPI Grassplot(LPVOID para) {
    int i = *(int *)para - CONSUMER_NUM;
    int ptr;
    int data;
    printf("%03d小草:小白兔快来找我!\n", i);
    Sleep(1800);

    while (1) {
        Sleep(rate * rand() % 10 + 1800);

        data = rand() % 4;
        printf("%03d小草:我要长大!data = %s!\n", i, thing[data]);
        P(g_semBuffer);
        P(g_mutex);
        ptr = g_buf.rear;
        g_buf.rear = (g_buf.rear + 1) % BUFFER_NUM;
        V(g_mutex);
        g_buf.product[ptr] = data;
        Sleep(rate / 2 * rand() % 10 + 1800);

        printf("%03d小草:我长大了!草放在buf[%d] = %s中 , 小白兔快来吃我!\n", i, ptr, thing[g_buf.product[ptr]]);
        V(g_semGlass);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    HANDLE hThread[CONSUMER_NUM + PRODUCER_NUM];
    int totalThreads = CONSUMER_NUM + PRODUCER_NUM;
    DWORD tid;
    int i = 0;

    g_mutex = CreateSemaphore(NULL, BUFFER_NUM, BUFFER_NUM, "mutexOfConsumerAndProducer");
    g_semBuffer = CreateSemaphore(NULL, BUFFER_NUM, BUFFER_NUM, "BufferSemaphone");
    g_semGlass = CreateSemaphore(NULL, 0, BUFFER_NUM, "ProductSemaphone");
    if (!g_semBuffer || !g_semGlass || !g_mutex) {
        printf("Create Semaphone Error ! \n");
        return -1;
    }
    printf("先请小白兔就位!\n");
    for (i = 0; i < CONSUMER_NUM; i++) {
        hThread[i] = CreateThread(NULL, 0, Rabbit, &i, 0, &tid);
        if (hThread[i]) WaitForSingleObject(hThread[i], 100);
    }
    printf("请小草就位!\n");
    for (; i < totalThreads; i++) {
        hThread[i] = CreateThread(NULL, 0, Grassplot, &i, 0, &tid);
        if (hThread[i]) WaitForSingleObject(hThread[i], 100);
    }
    WaitForMultipleObjects(totalThreads, hThread, TRUE, INFINITE);
    return 0;
}
