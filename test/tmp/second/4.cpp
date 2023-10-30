//
// Created by Leezed on 2023/10/30.
//
#include<stdio.h>

int main() {
    setbuf(stdout, NULL); //关闭缓冲区  这段代码可以不用管
    int year, month;
    printf("请输入年份和月份：");
    scanf("%d %d", &year, &month);
    //用switch判断每个月的天数
    int day;
    switch (month >= 1 && month <= 12) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            day = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            day = 30;
            break;
        case 2:
            //判断闰年
            if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
                day = 29;
            } else {
                day = 28;
            }
            break;
        default:
            printf("输入错误\n");
            return 0; //如果到这就代表程序出错了，直接返回
    }
    printf("%d年%d月有%d天\n", year, month, day);
    return 0;
}