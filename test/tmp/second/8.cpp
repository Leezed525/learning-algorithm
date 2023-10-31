//
// Created by Leezed on 2023/10/30.
//
#include <stdio.h>

int main() {
    setbuf(stdout, NULL);//关闭缓冲区  这段代码可以不用管
    int x;
    int count = 0;
    while (scanf("%d", &x) != EOF && count <= 50) {//scanf() != EOF的意思是输入到文件结束
        printf("%d\n", x * x);
        count += 1;
    }
}