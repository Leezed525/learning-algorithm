//
// Created by Leezed on 2023/12/16.
//
#include<stdio.h>
#include<stdlib.h>


void month_day(int year, int yearday, int *pmonth, int *pday) {
    int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        month[2] = 29;
    }
    int i = 1;
    while (yearday > month[i]) {
        yearday -= month[i];
        i++;
    }
    *pmonth = i;
    *pday = yearday;
}

int main() {
    setbuf(stdout, NULL);
    printf("请输入当前年份和天数\n");
    int year, days;
    scanf("%d%d", &year, &days);
    int *pmonth = (int *) malloc(1 * sizeof(int));//给指针分配内存
    int *day = (int *) malloc(1 * sizeof(int));//给指针分配内存

    month_day(year, days, pmonth, day);

    printf("%d-%d-%d\n", year, *pmonth, *day);
    

    return 0;
}