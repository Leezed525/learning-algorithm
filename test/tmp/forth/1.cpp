//
// Created by Leezed on 2023/11/26.
//
#include<stdio.h>

int main() {
    setbuf(stdout, NULL);
    int a[10], b[10], c[20];
    int count_a = 0, count_b = 0, count_c = 0;
    printf("请输入数组a：\n");
    while (scanf("%d", &a[count_a++]) != EOF && count_a < 10);
    printf("请输入数组b：\n");
    while (scanf("%d", &b[count_b++]) != EOF && count_b < 10);
    //检查a数组中有没有b数组中没出现的元素
    for (int i = 0; i < count_a; i += 1) {
        int flag = 0;
        for (int j = 0; j < count_b; j += 1) {
            if (a[i] == b[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            c[count_c++] = a[i];
        }
    }
    //检查b数组中有没有a数组中没出现的元素
    for (int i = 0; i < count_b; i += 1) {
        int flag = 0;
        for (int j = 0; j < count_a; j += 1) {
            if (b[i] == a[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            c[count_c++] = b[i];
        }
    }
    //输出
    for (int i = 0; i < count_c; i += 1) {
        printf("%d ", c[i]);
    }
    return 0;

}