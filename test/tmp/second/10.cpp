//
// Created by Leezed on 2023/10/30.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    setbuf(stdout, NULL);//关闭缓冲区  这段代码可以不用管
    //猜数游戏
    srand((unsigned) time(NULL));
    int x, y;
    //生成一个1 - 100 的数
    y = rand() % 100 + 1;
    printf("开始猜数\n");
    bool flag = false;
    for (int i = 0; i < 7; i += 1) {
        printf("第%d次猜数：", i + 1);
        printf("请输入一个1 - 100 的数：");
        scanf("%d", &x);
        if (x == y) {
            printf("恭喜你%d次猜对了\n", i + 1);
            flag = true;
            break;
        } else if (x > y) {
            printf("你猜的数大了\n");
        } else {
            printf("你猜的数小了\n");
        }
    }
    if (!flag) {
        printf("太可惜了，你还没猜对，答案是%d，想想二分法，100以内的数7次必定才出来的哦！^_^\n", y);
    }
    return 0;
}