#include<stdio.h>
#include<stdlib.h>
struct Time{
    int hour;
    int minute;
    int second;
};
int main(){
    setbuf(stdout, NULL);
    int n;
    struct Time *time;
    int seconds;
    time = (Time *) malloc(sizeof(Time));
    printf("请输入一个时间数值：");
    scanf("%d-%d-%d",&time->hour,&time->minute,&time->second);
    printf("请输入一个秒数：");
    scanf("%d",&n);
    time->second += seconds;
    if (time->second>=60) {
        int minutesToAdd=time->second/60;
        time->second%=60;
        time->minute+=minutesToAdd;

        if (time->minute>=60) {
            int hoursToAdd=time->minute / 60;
            time->minute%=60;
            time->hour+=hoursToAdd;

            if (time->hour>=24) {
                time->hour%=24;
            }
        }
    }
    printf("时间再过%d秒后的值为：%d:%d:%d\n",n, time->hour, time->minute, time->second);
    free(time);
    return 0;
}