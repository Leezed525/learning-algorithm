//
// Created by Leezed on 2023/11/13.
//
#include<stdio.h>

//朴素的gcd写法
int norm_gcd(int a, int b){
    while(b){
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

//简洁的gcd写法
int simp_gcd(int a, int b){
    return b ? simp_gcd(b, a % b) : a;//三元表达式
}


int main(){
    setbuf(stdout, NULL);
    int a,b;
    while(scanf("%d%d",&a,&b) != EOF){
        printf("朴素gcd: %d\n", norm_gcd(a, b));
        printf("简洁gcd: %d\n", simp_gcd(a, b));
        printf("\n");
    }
}