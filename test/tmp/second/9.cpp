//
// Created by Leezed on 2023/10/30.
//
#include<stdio.h>
#include<math.h>

int main() {
    setbuf(stdout, NULL); //关闭缓冲区  这段代码可以不用管
    //手动泰勒展开求sin函数
    double x;
    printf("请输入x的值：");
    scanf("%lf", &x);
    double ans = 0;
    double tmp = x;
    ans += tmp;
    int n = 2;
    //上面完成了泰勒展开式的第一项的计算
    while (fabs(tmp) >= 1e-5) { //c语言中1e-5 == 0.00001
        //求展开式中的x的(2n - 1)次方
        double tmpx = pow(x, 2 * n - 1);
        //求展开式中的（2n - 1）!
        double tmpk = 1;
        for (int i = 1; i <= (2 * n - 1); i += 1) {//求阶乘这件事等学到函数后可以使用函数代替
            tmpk *= i;
        }
        //求展开式中的(-1)^(n + 1)
        double tmpf = pow(-1, n + 1);
        tmp = tmpx / tmpk * tmpf;
        ans += tmp;
        n += 1; //迭代
    }
    //以上只是一个比较好理解的写法，也有很简便的写法，我这里就不赘述了

    printf("使用math库中的方法：sin(%.2lf) = %.5lf\n", x, sin(x));//前人的智慧
    printf("手动使用泰勒展开的方法：sin(%.2lf) = %.5lf\n", x, ans);

}