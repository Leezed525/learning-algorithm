//
// Created by Leezed on 2024/1/6.
//
//将字符写入文件，从键盘输入一行字符，写到文件myfile.txt
#include<stdio.h>

int main() {
    setbuf(stdout, NULL);

    FILE *fp = fopen("./myfile.txt", "w");
    char c;
    while ((c = getchar()) != '\n') {
        fputc(c, fp);
    }
    fclose(fp);

    return 0;
}