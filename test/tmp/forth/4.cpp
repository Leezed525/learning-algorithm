//
// Created by Leezed on 2023/11/26.
//
#include <stdio.h>

int count_num(int x) {
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    int a[100];//假设最多可以输入100个数字
    int count = 0;
    while (scanf("%d", &a[count]) != EOF) {
        count += 1;
        if (count == 100) {
            break;
        }
    }
    //根据每个数的count_sum来冒泡排序
    for (int i = 0; i < count - 1; i += 1) {
        for (int j = 0; j < count - i - 1; j += 1) {
            if (count_num(a[j]) > count_num(a[j + 1])) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }

    //输出
    for (int i = 0; i < count; i += 1) {
        printf("%d ", a[i]);
    }

    return 0;
}