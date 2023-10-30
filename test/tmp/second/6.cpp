//
// Created by Leezed on 2023/10/30.
//
#include<stdio.h>

int main() {
    setbuf(stdout, NULL);//关闭缓冲区  这段代码可以不用管
    for (int i = 0; i < 4; i += 1) {
        printf("输入第%d个数：", i + 1);
        double tmp;
        scanf("%lf", &tmp);
        printf("第%d个数四舍五入保留两位小数是%.2lf\n", i + 1, tmp);//其实c语言使用占位符格式化的时候，会自动帮我们进行四舍五入(对于浮点数而言)
    }
}
