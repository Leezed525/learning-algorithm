//
// Created by Leezed on 2023/11/13.
//
#include<stdio.h>
#include<math.h>

int main(){
    setbuf(stdout, NULL);
    double last = 2,current = 1;//随便初始化数，只要不是0就行
    double a;
    scanf("%lf",&a);
    while(fabs(last - current) > 1e-10){
        last = current;
        current = (last + a / last) / 2;
    }
    printf("%.10lf\n",current);
    return 0;
}
