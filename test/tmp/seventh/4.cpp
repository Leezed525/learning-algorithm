//
// Created by Leezed on 2023/12/28.
//
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void sort(int *array, int len) {
    //冒泡排序
    for (int i = 0; i < len; i += 1) {
        for (int j = 1; j < len - i; j += 1) {
            if (array[j - 1] > array[j]) {
                int temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

//二分查找
int binarySearch(int *array, int len, int x) {
    int left = 0;
    int right = len;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] == x) {
            return mid;
        } else if (array[mid] > x) {
            right = mid - 1;
        } else if (array[mid] < x) {
            left = mid + 1;
        }
    }
    return -1;
}


int main() {
    setbuf(stdout, NULL);
    int a[10];
    //通过随机数生成10个数字
    srand((unsigned) time(NULL));
    for (int i = 0; i < 10; i++) {
        a[i] = rand() % 100;
    }
    sort(a, 10);
    printf("当前数组元素为：");
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n请输入你要查找的数字：");
    int x;
    scanf("%d", &x);
    int flag = binarySearch(a, 10, x);
    if (flag == -1) {
        printf("Not found");
    } else {
        printf("找到了该数字，下标为%d", flag);
    }


    return 0;
}