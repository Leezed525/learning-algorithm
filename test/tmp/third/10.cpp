//
// Created by Leezed on 2023/11/13.
//
#include<stdio.h>

//使用循环的方法求组合数
int C(int n, int m){
    int ans = 1;
    for(int i = 1; i <= m; i += 1){
        ans = ans * (n - i + 1) / i;
    }
    return ans;
}

//使用递归的方法求组合数
int C2(int n, int m){
    if(m == 0 || m == n){
        return 1;
    }else{
        return C2(n - 1, m - 1) + C2(n - 1, m);
    }
}

int main(){
    int n,m;
    scanf("%d%d", &n, &m);
    printf("循环方法：%d\n", C(n, m));
    printf("递归方法：%d\n", C2(n, m));
}