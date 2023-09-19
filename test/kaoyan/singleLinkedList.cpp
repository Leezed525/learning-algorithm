#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#define ms(x, n) memset(x, n, sizeof(x));

using namespace std;
//*(int(*)[10])arr_name
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
inline int lowbit(int x) { return x & -x; }

typedef struct Lnode {
    int data;
    struct Lnode *next;
} Lnode, *LinkedList;

void initList(LinkedList &head) {
    head = (LinkedList)malloc(sizeof(Lnode));
    head->data = 0;
    head->next = NULL;
}

void headInsertList(LinkedList &head) {
    int data[10] = {5, 1, 3, 4, 2, 7, 0, 9, 8, 6};
    int i = 0;
    Lnode *tmp;
    while (i < 10) {
        tmp = (Lnode *)malloc(sizeof(Lnode));
        tmp->data = data[i];
        tmp->next = head->next;
        head->next = tmp;
        i += 1;
    }
}

void tailInsertList(LinkedList &head) {
    int data[10] = {5, 1, 3, 4, 2, 7, 0, 9, 8, 6};
    int i = 0;
    Lnode *tmp;
    LinkedList tail = head;
    while (i < 10) {
        tmp = (Lnode *)malloc(sizeof(Lnode));
        tmp->data = data[i];
        tmp->next = NULL;
        tail->next = tmp;
        tail = tmp;
        i+= 1;
    }
}

void printList(LinkedList &head) {
    Lnode *p = head->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void freeList(LinkedList &head){
    int i = 0;
    while(head){
        Lnode *tmp = head;
        head = head->next;
        free(tmp);
        i += 1;
    }
    cout << i << endl;
}

int main() {
    LinkedList head;
    initList(head);
    // 头插法
    headInsertList(head);
    printList(head);
    freeList(head);
    // 尾插法
    cout << "init" << endl;
    initList(head);
    cout << "init finished" << endl;
    tailInsertList(head);
    printList(head);

    system("pause");
    return 0;
}