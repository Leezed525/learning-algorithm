#include <stdio.h>

int main() {
    int i1, i2;//定义变量
    float f1, f2; //定义变量
    char c1; //定义变量
    scanf("%d%d%5f%c%5f", &i1, &i2, &f1, &c1, &f2); //输入对应数据
    printf("i1=%d,i2=%d,f1=%.3f,f2=%.3f,c1=%c\n", i1, i2, f1, f2, c1);//输出对应结果
}
