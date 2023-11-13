//
// Created by Leezed on 2023/11/13.
//
#include<stdio.h>

//判断一个数是不是素数
int isPrime(int x) {
    if (x <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= x; i += 1) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int x;
    scanf("%d", &x);
    if (isPrime(x)) {
        printf("是素数\n");
    } else {
        printf("不是素数\n");
    }
    return 0;
}