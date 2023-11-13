//
// Created by Leezed on 2023/11/13.
//
#include<stdio.h>

int main() {
    setbuf(stdout, NULL);
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i += 1) {
            printf("%2d", i + 1);
            for (int j = 0; j < n; j += 1) {
                printf("  %3d", (i + j) % n);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}