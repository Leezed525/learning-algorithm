#include<stdio.h>

int jiecheng();

int main(){
    int ans = jiecheng();
    printf("%d\n",ans);
    bool flag1 = true;
    bool flag2 = false;
    if (flag2, flag1) {
        printf("yes");
    }
    return 0;
}

int jiecheng(){
    int ans = 1;
    for (int i = 0;i < 10 ;i += 1){
        ans *= i;
    }
    return ans;
}