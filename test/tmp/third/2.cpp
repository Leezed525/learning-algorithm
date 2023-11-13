//
// Created by Leezed on 2023/11/13.
//
#include<stdio.h>

int main() {
    for (int i = 0; i <= 100 / 3; i += 1) {//枚举大鸡
        for (int j = 0; j <= 100 / 2; j += 1) {//枚举中鸡
            for (int k = 0; k <= 100; k += 1) {//枚举小鸡（其实小鸡不枚举也行）
                if (i * 3 + j * 2 + k == 100 && i + j + k * 3 == 100) {
                    printf("大鸡：%d只，中鸡：%d只，小鸡：%d只\n", i, j, k * 3);
                }
            }
        }
    }
    return 0;
}