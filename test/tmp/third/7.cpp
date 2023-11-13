//
// Created by Leezed on 2023/11/13.
//
#include<stdio.h>

int even(int x){
    if (x % 2 == 0) {
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int sum = 0, n;
    while(scanf("%d", &n) != EOF){
        if (n <= 0) {
            break;
        }
        if(!even(n)){
            sum += n;
        }
    }
    printf("%d\n", sum);
}