//
// Created by Leezed on 2023/12/8.
//
#include<stdio.h>
#include<cstring>

int main(){
    char str[100];
    gets(str);
    int length = strlen(str);
    //如果有连续的空格，只输出一个空格
    bool flag = false;
    for (int i = 0; i < length; i += 1) {
        //判断当前字符是否为空格
        if (str[i] == ' ') {
            //判断前一个字符是否为空格
            if (flag) {
                continue;
            }
            flag = true;
        } else {
            flag = false;
        }
        printf("%c", str[i]);
    }
    return 0;
}