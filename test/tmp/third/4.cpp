//
// Created by Leezed on 2023/11/13.
//
#include<stdio.h>
int main(){
    setbuf(stdout, NULL);
    int top,h;
    while (scanf("%d%d", &top, &h) != EOF) {
        for (int i = 0; i < h; i += 1) {
            for (int j = 0; j < top + i; j += 1) {
                printf("A");
            }
            printf("\n");
        }
        printf("\n");
    }
}