//
// Created by Leezed on 2023/12/16.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    setbuf(stdout, NULL);
    char str[100];
    while (gets(str)) {
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == '1') {
                printf("0");
            } else {
                printf("1");
            }
        }
        printf("\n");
    }

    return 0;
}