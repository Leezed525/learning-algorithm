#include <stdio.h>
#include <math.h>

int main() {
    double x, y, z; //定义变量
    scanf("%lf%,%lf", &x, &y); //输入对应数据
    z = pow(x, y);
    printf("%lf\n", z); //输出对应结果
    return 0;
}
