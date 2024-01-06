//
// Created by Leezed on 2024/1/6.
//
#include <stdio.h>
#include <cstring>

typedef struct {
    char name[50];
    char number[50];
} info;

// 比较函数
bool cmp(info a, info b) {
    return strcmp(a.name, b.name) > 0;
}

//排序函数
bool sort(info a[], int n) {
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n - i - 1; j += 1) {
            if (cmp(a[j], a[j + 1])) {
                info temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

//输出函数
void output(info a[], int n) {
    for (int i = 0; i < n; i += 1) {
        printf("%s %s\n", a[i].name, a[i].number);
    }
}

int main() {
    setbuf(stdout, NULL);
    printf("请输入n(要输入多少人的数据):\n");
    int n;
    scanf("%d", &n);

    info a[n];
    for (int i = 0; i < n; i += 1) {
        scanf("%s%s", a[i].name, a[i].number);
    }
    sort(a, n);
    output(a, n);

    return 0;
}

/*
4
zhangsan 19999995643
lisi 15478885462
wangwu 13242551567
zhaoliu 13242551567

 */