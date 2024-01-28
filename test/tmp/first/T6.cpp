#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));//随机数种子
    rand();//舍去重复性较高的第一位
    int i = rand();
    printf("%d\n", i);//输出随机数
    return 0;
}
