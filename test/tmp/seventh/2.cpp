//
// Created by Leezed on 2023/12/28.
//
#include<stdio.h>
#include<string.h>


char *removeAdjacentDigits(char *str) {
    int len = strlen(str);
    int new_len = 0;
    for (int i = 0; i < len; i += 1) {
        if (i == 0) {
            str[new_len++] = str[i];
        } else {
            if (str[i] != str[i - 1]) {//判断当前字符是否和上个字符相同
                str[new_len++] = str[i];
            } else {//当前字符和上个字符相同
                if (str[i] >= '0' && str[i] <= '9') {//如果是数字的话就不填充
                    continue;
                } else { //不是数字就不管
                    str[new_len++] = str[i];
                }
            }
        }
    }
    str[new_len] = '\0';
    return str;
}

int main() {
    setbuf(stdout, NULL);
    char str[100];
    printf("请输入一个字符串，不超过100个字符:\n");
    gets(str);
    printf("去除相邻重复数字后的字符串为:\n");
    printf("%s", removeAdjacentDigits(str));
    return 0;
}