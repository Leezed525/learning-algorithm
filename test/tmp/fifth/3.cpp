//
// Created by Leezed on 2023/12/8.
//
#include<stdio.h>
#include<cstring>

int main() {
    setbuf(stdout, NULL);
    char str[4][61];
    //读入四行字符
    for (int i = 0; i < 4; i++) {
        gets(str[i]);
    }
    for (int i = 0; i < 4; i += 1) {
        int length = strlen(str[i]);
        for (int j = 1; j < length; j += 1) {
            //判断前一个字符是否为空格并且当前字符是否为小写字母
            if (str[i][j - 1] == ' ' && str[i][j] >= 'a' && str[i][j] <= 'z') {
                //将当前字符转换为大写字母
                str[i][j] -= 32;
            }
        }
        puts(str[i]);
    }
    return 0;
}