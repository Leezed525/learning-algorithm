//
// Created by Leezed on 2023/10/30.
//
#include<stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    if (x % 3 == 0)
        printf("该数%d能被3整除\n", x);
    else
        printf("该数%d不能被3整除\n", x);
    if (x % 5 == 0)
        printf("该数%d能被5整除\n", x);
    else
        printf("该数%d不能被5整除\n", x);
    if (x % 7 == 0)
        printf("该数%d能被7整除\n", x);
    else
        printf("该数%d不能被7整除\n", x);
}