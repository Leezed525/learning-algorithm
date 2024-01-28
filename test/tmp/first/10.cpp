#include <stdio.h>

int main() {
    int i1; //定义变量
    char c1; //定义变量
    float f1; //定义变量
    double d1; //定义变量
    scanf("%d$%c%f%lf", &i1, &c1, &f1, &d1); //输入对应数据
    printf("i1=%d c1=%c f1=%f d1=%lf", i1, c1, f1, d1); //输出对应结果
    return 0;
}
