//
// Created by Leezed on 2023/12/16.
//
#include<stdio.h>
#include<cstring>

int main() {
    setbuf(stdout, NULL);

    char *str[] = {"blue", "yellow", "black", "green", "red"};

    char color[100];
    printf("请输入一个颜色的单词:\n");
    gets(color);

    //判断颜色是否在上面又出现
    int flag = -1;
    for (int i = 0; i < 5; i++) {
        if (strcmp(color, str[i]) == 0) {
            flag = i;
            break;
        }
    }

    //输出结果
    if (flag == -1) {
        printf("Not Found\n");
    } else {
        printf("颜色出现的位置为%d\n", flag);
    }

    return 0;
}