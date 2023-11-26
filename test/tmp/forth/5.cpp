//
// Created by Leezed on 2023/11/26.
//
#include<stdio.h>

int main() {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //输入要查找的数
    int need_find_num;
    scanf("%d", &need_find_num);
    //顺序查找
    int flag = 0;
    for (int i = 0; i < 10; i += 1) {
        if (a[i] == need_find_num) {
            flag = 1;
            printf("顺序查找找到了，下标是%d,查找次数为%d\n", i, i + 1);
            break;
        }
    }
    if (flag == 0) {
        printf("Not Found\n");
    }
    //二分查找
    int left = 0, right = 9, find_count = 0;
    flag = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        find_count += 1;
        if (a[mid] == need_find_num) {
            flag = 1;
            printf("二分查找找到了，下标是%d,查找次数为%d\n", mid, find_count);
            break;
        } else if (a[mid] < need_find_num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (flag == 0) {
        printf("Not Found\n");
    }
    return 0;
}