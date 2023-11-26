//
// Created by Leezed on 2023/11/26.
//
#include<stdio.h>

int main() {

    //使用插入法对最多十个数字进行排序
    int a[10];
    int count = 0;
    while (scanf("%d", &a[count]) != EOF) {
        count += 1;
        int tmp = a[count - 1];
        int i = count - 2;
        while (i >= 0 && a[i] < tmp) { //从后往前找到第一个比tmp小的数，并移位
            a[i + 1] = a[i];
            i -= 1;
        }
        a[i + 1] = tmp;

        if (count == 10) {
            break;
        }
    }

    //输出
    for (int i = 0; i < count; i += 1) {
        printf("%d ", a[i]);
    }

    return 0;
}