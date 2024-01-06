//
// Created by Leezed on 2024/1/6.
//
#include<stdio.h>

typedef struct {
    int hour, minute, second;
} Time;

int main(){
    setbuf(stdout, NULL);

    printf("请输入一个时间(格式为hh:mm:ss):\n");
    Time time;
    scanf("%d:%d:%d", &time.hour, &time.minute, &time.second);

    printf("请输入一个秒数(n<60):\n");
    int n;
    scanf("%d", &n);

    //更新时间
    time.second += n;
    if (time.second >= 60) {
        time.second %= 60;
        time.minute += 1;
        if (time.minute >= 60) {
            time.minute %= 60;
            time.hour += 1;
            if (time.hour >= 24) {
                time.hour %= 24;
            }
        }
    }
    printf("时间再过%d秒后的值为：%d:%d:%d\n", n, time.hour, time.minute, time.second);

    return 0;
}