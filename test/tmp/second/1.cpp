//
// Created by Leezed on 2023/10/30.
//
#include<stdio.h> //头文件打错了

int main() {
    int x, y;
    scanf("%d", &x);//源文件没有输入

    y = x * x;
    printf("%d = %d * %d\n", y, x, x);//源文件的占位符和变量对应不全
    printf("%d * %d = %d\n", x, x, y);//源文件第一个占位符的%d打成了d，且占位符对应不全

    return 0;
}