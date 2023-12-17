//
// Created by Leezed on 2023/12/16.
//
#include<stdio.h>
#include<stdlib.h>


int main() {
    setbuf(stdout, NULL);
    int n;
    printf("输入学生人数:\n");
    scanf("%d", &n);

    int *a = (int *) malloc(n * sizeof(int));

    printf("输入学生成绩:\n");
    for (int i = 0; i < n; i += 1) {
        printf("请输入第%d个学生的成绩：", i + 1);
        scanf("%d", a + i);
    }

    //计算平均数,找到最大值和最小值
    int sum = 0;
    int max = 0;
    int min = 100000;
    for (int i = 0; i < n; i += 1) {
        sum += *(a + i);//计算总和
        if (*(a + i) > max) {//找最大值
            max = *(a + i);
        }
        if (*(a + i) < min) {//找最小值
            min = *(a + i);
        }
    }


    printf("平均分为:%.2lf\n", sum * 1.0 / n);
    printf("最高分为:%d\n", max);
    printf("最低分为:%d\n", min);

    return 0;

}