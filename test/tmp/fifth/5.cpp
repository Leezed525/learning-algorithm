//
// Created by Leezed on 2023/12/8.
//
#include<stdio.h>
#include<cstring>


int main(){
    setbuf(stdout, NULL);
    char str[100];
    gets(str);
    int length = strlen(str);
    //记录大写字母是否出现的数组
    int a[26] = {0};
    bool flag = true;//用来记录当前程序有没有输出过
    for (int i = 0; i < length; i += 1) {
        //判断当前字符是否为大写字母
        if (str[i] >= 'A' && str[i] <= 'Z') {
            //判断当前字符是否出现过
            if (a[str[i] - 'A'] == 0) {
                //如果没出现过就输出
                printf("%c", str[i]);
                flag = false;
            }
            //记录当前字符
            a[str[i] - 'A'] = 1;
        }
    }
    if(flag) {
        printf("Not Found\n");
    }
    return 0;
}