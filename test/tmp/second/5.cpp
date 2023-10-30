//
// Created by Leezed on 2023/10/30.
//
#include<stdio.h>
#include<math.h>

int main() {
    setbuf(stdout, NULL); //关闭缓冲区  这段代码可以不用管
    double money, rate;
    int year;
    printf("请输入本金、存款年数、年利率：");
    scanf("%lf %d %lf", &money, &year, &rate);

    double interest = money * pow(1 + rate, year) - money;
    printf("本金%.2lf元，存款%d年，年利率%.2lf%%，利息%.2lf元\n", money, year, rate, interest);

}
