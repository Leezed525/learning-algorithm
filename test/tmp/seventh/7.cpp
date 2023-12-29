//
// Created by Leezed on 2023/12/29.
//
#include<stdio.h>

//struct tensor{ //c++语法结构体可以直接这样定义
//    int x, y;
//};

typedef struct {// c语言语法结构体需要这样定义
    int x, y;
} tensor;

int main() {
    setbuf(stdout, NULL);
    tensor a, b;
    printf("请输入第一个向量的x和y值:\n");
    scanf("%d%d", &a.x, &a.y);
    printf("请输入第二个向量的x和y值:\n");
    scanf("%d%d", &b.x, &b.y);
    tensor c = {a.x + b.x, a.y + b.y};
    printf("两个向量相加的结果为:\n");
    printf("x=%d,y=%d\n", c.x, c.y);
    return 0;
}