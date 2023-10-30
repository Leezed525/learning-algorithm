//
// Created by Leezed on 2023/10/30.
//
#include <stdio.h>
#include <math.h>

int main() {
    setbuf(stdout, NULL); //关闭缓冲区  这段代码可以不用管
    double a, b, c, d;

    printf("Enter a, b, c: ");
    scanf("%lf%lf%lf", &a, &b, &c);
    d = b * b - 4 * a * c;     /* 调试时设置断点 */
    if (a == 0) {//源文件的判断条件写成了赋值语句
        if (b == 0) {
            if (c == 0)
                printf("参数都为零，方程无意义!\n");
            else
                printf("a和b为0，c不为0，方程不成立\n");
        } else
            printf("x = %0.2f\n", -c / b);
    } else if (d >= 0) {      /* 调试时设置断点 *///源文件这里的elseif没有加花括号导致语句少执行了一句
        printf("x1 = %0.2f\n", (-b + sqrt(d)) / (2 * a));
        printf("x2 = %0.2f\n", (-b - sqrt(d)) / (2 * a));
    } else {
        printf("x1 = %0.2f + %0.2fi\n", -b / (2 * a), sqrt(-d) / (2 * a));
        printf("x2 = %0.2f - %0.2fi\n", -b / (2 * a), sqrt(-d) / (2 * a));
    }

    return 0;          /* 调试时设置断点 */
}
