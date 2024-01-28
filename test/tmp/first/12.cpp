#include <stdio.h>
#include <math.h>

int main() {
    float a1, a2, a3, s, d; //定义变量
    scanf("%f%f%f", &a1, &a2, &a3); //输入对应数据
    s = (a1 + a2 + a3) / 2;
    s = sqrt(s * (s - a1) * (s - a2) * (s - a3));
    printf("边长为%.2f,%.2f,%.2f的三角形面积为：%-10.3f\n", a1, a2, a3, s); //输出对应结果
    return 0;
}
