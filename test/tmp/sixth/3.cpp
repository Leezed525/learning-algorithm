//
// Created by Leezed on 2023/12/16.
//
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//插入十个随机数
void insert_random_number(int *tmp) {
    for (int i = 0; i < 10; i++) {
        tmp[i] = rand() % 100;
    }
}

int main() {
    setbuf(stdout, NULL);
    int a[10];
    int *b = (int *) malloc(10 * sizeof(int));

    //初始化随机数种子
    srand((unsigned) time(NULL));

    //生成随机数数组
    insert_random_number(a);
    insert_random_number(b);

    //输出数组
    printf("a数组为\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("b数组为\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", b[i]);
    }

    printf("\n");

    //使用数组的方法计算a数组总和
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += a[i];
    }

    //使用指针的方法计算b数组总和
    int sum2 = 0;
    for (int i = 0; i < 10; i++) {
        sum2 += *(b + i);
    }

    //输出
    printf("a数组总和为%d\n", sum);
    printf("b数组总和为%d\n", sum2);
    return 0;
}