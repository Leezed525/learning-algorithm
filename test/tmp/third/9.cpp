//
// Created by Leezed on 2023/11/13.
//
#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("0\n");
    }else{
        while(n){
            printf("%d", n % 10);
            n /= 10;
        }
        printf("\n");
    }
    return 0;
}