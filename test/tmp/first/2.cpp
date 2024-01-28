#include <stdio.h>

int main() {
    int a, b, c; //定义变量
    a = b = c = 0;
    scanf("%d%*d%d", &a, &c); //输入对应数据
    printf("a=%d,b=%d,c=%d\n", a, b, c); //输出对应结果
    return 0;
}
