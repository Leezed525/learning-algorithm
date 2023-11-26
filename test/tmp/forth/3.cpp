//
// Created by Leezed on 2023/11/26.
//
#include <stdio.h>


int day_of_yead(int year, int month, int day) {
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        days[2] = 29;
    }
    int sum = 0;
    for (int i = 0; i < month; i += 1) {
        sum += days[i];
    }
    sum += day;
    return sum;
}

int main() {
    setbuf(stdout, NULL);
    int year, month, day;
    printf("请输入年/月/日：\n");
    scanf("%d/%d/%d", &year, &month, &day);
    printf("这是这一年的第%d天\n", day_of_yead(year, month, day));
    return 0;
}