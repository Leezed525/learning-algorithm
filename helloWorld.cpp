#include<bits/stdc++.h>

int main(){

    //初始化随机数种子

    //生成100个随机数并输出
    for(int i = 0; i < 100; i += 1){
        srand((unsigned)time(NULL));
        
        printf("%d ", rand() % 100);
    }
}
