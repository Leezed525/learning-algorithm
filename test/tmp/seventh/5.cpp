//
// Created by Leezed on 2023/12/28.
//
#include<stdio.h>

//将十进制转换成十六进制
void f(long int x, char *p) {
    int i = 0;
    while (x) {
        int temp = x % 16;
        if (temp < 10) {
            p[i++] = temp + '0';
        } else {
            p[i++] = temp - 10 + 'A';
        }
        x /= 16;
    }
    p[i] = '\0';
    printf("转换后的十六进制数为:\n");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", p[j]);
    }
}

int main() {
    setbuf(stdout, NULL);
    long int x;
    char str[100];
    printf("请输入一个十进制数:\n");
    scanf("%ld", &x);
    f(x, str);
    return 0;
}