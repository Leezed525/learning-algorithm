//
// Created by Leezed on 2023/12/13.
//
#include<stdio.h>


int main() {
    setbuf(stdout, NULL);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        int a[110];
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        //冒泡排序
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (a[j] > a[j + 1]) {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }

        //判断是否顺序，就是相邻两个数差是否为1
        int flag = 1;
        for (int i = 0; i < n - 1; i++) {
            if (a[i + 1] - a[i] != 1) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("yes\n");
        } else {
            printf("no\n");
        }

    }
    return 0;
}