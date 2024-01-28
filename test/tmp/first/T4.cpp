#include <stdio.h>

#define PI 3.1415

int main() {
    double r1, r2, h;//定义变量
    scanf("%lf%lf%lf", &r1, &r2, &h);//输入对应数据
    printf("%lf", (PI * r2 * r2 - PI * r1 * r1) * h); //输出对应结果
    return 0;
}
