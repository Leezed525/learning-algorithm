#include <stdio.h>

int main() {
    char ch = getchar();//输入字符
    int x = int(ch);//转为ascll码
    printf("%d,%o,%x\n", x, x, x);//输出相应答案
    return 0;
}
