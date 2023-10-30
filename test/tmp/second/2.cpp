//
// Created by Leezed on 2023/10/30.
//
#include<stdio.h>
int main(){
    double x, y;
    printf("Enter x:");
    scanf("%lf", &x);//源文件输入没有& 且源文件的占位符打成了1f(一f)
    if (x != 0) {
        y = 1 / x; //源文件没有加分号
    }
    else{
        y = 0;
    }
    printf("f(%.2lf) = %.1lf\n", x, y);//源文件的占位符打成了1f(一f),且第一个占位符对应错误
}