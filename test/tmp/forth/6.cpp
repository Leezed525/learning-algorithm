//
// Created by Leezed on 2023/11/26.
//
#include<stdio.h>

//判断一个数字是否是完数
int find_perfect(int x) {
    int sum = 0;
    for (int i = 1; i < x; i += 1) {
        if (x % i == 0) {
            sum += i;
        }
    }
    if (sum == x) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    for (int i = 1; i <= 1000; i += 1) {
        if (find_perfect(i)) {
            printf("%d ", i);
        }
    }
}