//
// Created by Leezed on 2023/12/8.
//
#include<stdio.h>

int main(){
    setbuf(stdout, NULL);
    //打印杨辉三角
    int n;
    scanf("%d", &n);
    int a[100][100];
    //初始化杨辉三角
    for (int i = 0; i < n; i += 1) {
        a[i][0] = 1;
        a[i][i] = 1;
    }
    for (int i = 2; i < n; i += 1) {
        for (int j = 1; j < i; j += 1) {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }
    //打印杨辉三角
    for (int i = 0; i < n; i += 1) {
        //打印空格
        for (int j = 0; j < n - i - 1; j += 1) {
            printf("    ");
        }
        for (int j = 0; j <= i; j += 1) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}