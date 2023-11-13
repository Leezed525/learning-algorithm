//
// Created by Leezed on 2023/11/13.
//
#include<stdio.h>

int main(){
    //正序打印九九乘法表
    printf("正序九九乘法表:\n");
    for(int i = 1; i <= 9; i += 1){
        for(int j = 1; j <= i; j += 1){
            printf("%d * %d = %d\t", j, i, i * j);
        }
        printf("\n");
    }

    //逆序打印九九乘法表
    printf("逆序九九乘法表:\n");
    for(int i = 9; i >= 1; i -= 1){
        for(int j = 1; j <= i; j += 1){
            printf("%d * %d = %d\t", j, i, i * j);
        }
        printf("\n");
    }
}