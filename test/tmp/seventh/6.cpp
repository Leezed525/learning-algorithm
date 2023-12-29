//
// Created by Leezed on 2023/12/28.
//
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main() {
    setbuf(stdout, NULL);
    char *str[] = {"一叶轻舟向东流", "帆梢轻握杨柳手", "风纤碧波微起舞", "顺水任从雅客悠"};
    for (int i = 0; i < 4; i += 1) {
        for (int j = 0; j < strlen(str[i]); j += 1) {
//        for (int j = 0; j < 2; j += 1) {
            printf("%c", str[i][j]);
        }
        printf("\n");

    }
    char poem[13];
    //输出每个诗的第一个字(因为我这个文件是utf-8格式的，所以一个中文字符占3位)
    for (int i = 0; i < 4; i++) {
        poem[3 * i] = str[i][0];
        poem[3 * i + 1] = str[i][1];
        poem[3 * i + 2] = str[i][2];
    }
    poem[12] = '\0';

//    char poem[9];
//    //如果是其他格式，比如gbk，那么一个中文字符占2位
//    for (int i = 0; i < 4; i++) {
//        poem[2 * i] = str[i][0];
//        poem[2 * i + 1] = str[i][1];
//    }
//    poem[8] = '\0';

    printf("真实含义为:\n");
    puts(poem);
//    system("pause");
    return 0;
}