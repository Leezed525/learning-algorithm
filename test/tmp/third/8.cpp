//
// Created by Leezed on 2023/11/13.
//
#include<stdio.h>

void print_triangle(int line, char ch){
    for(int i = 0; i < line; i += 1){
        for(int j = 0; j < 2 * i + 1; j += 1){
            printf("%c", ch);
        }
        printf("\n");
    }
}

int main(){
    setbuf(stdout, NULL);
    int n;
    char ch;
    printf("How many lines?:");
    scanf("%d", &n);
    printf("Which character?:");
    getchar();//吸收掉上一次输入的回车
    scanf("%c", &ch);
    print_triangle(n, ch);
}