#include<stdio.h>

const int n = 5;
struct teacher {//老师结构体
    char name[100];
    int number, tim;
    char job[100];
} a[10];

void pt_inf(struct teacher p) {//输出函数
    printf("%8s %12d %8d %8s\n", p.name, p.number, p.tim, p.job);
    return;
}

void swap_(struct teacher *x, struct teacher *y) {//交换函数
    struct teacher temp;
    temp = *x;
    *x = *y;
    *y = temp;
    return;
}

void pt0(struct teacher *a, int n) {//储存数据到teacher1
    FILE *fp = fopen("teacher1.txt", "w");
    for (int i = 1; i <= n; i++) {
        fprintf(fp, "%8s %12d %8d %8s\n", a[i].name, a[i].number, a[i].tim, a[i].job);
    }
    fclose(fp);
    return;
}

void pt1(struct teacher *a, int n) {//筛选2005年以后的老师
    printf("2005年后参加工作的教师\n");
    for (int i = 1; i <= n; i++) {
        if (a[i].tim >= 2005) {
            pt_inf(a[i]);
        }
    }
    return;
}

void pt2(struct teacher *a, int n) {//按照参加工作时间先后输出
    printf("按照参加工作时间先后输出\n");
    for (int i = 1; i <= n; i++) {//冒泡排序
        for (int j = i + 1; j <= n; j++) {
            if (a[i].tim > a[j].tim) {
                swap_(&a[i], &a[j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        pt_inf(a[i]);
    }
    return;
}

void pt3(struct teacher *a, int n) {//储存数据到teacher2
    FILE *fp = fopen("teacher2.txt", "w");
    //操作2中已经排序完毕
    for (int i = 1; i <= n; i++) {
        fprintf(fp, "%8s %12d %12d %8s\n", a[i].name, a[i].number, a[i].tim, a[i].job);
    }
    fclose(fp);
    return;
}

int main() {
    for (int i = 1; i <= n; i++) {
        scanf("%s%d%d%s", a[i].name, &a[i].number, &a[i].tim, a[i].job);
    }
    pt0(a, n);//储存数据
    pt1(a, n);//操作1
    pt2(a, n);//操作2
    pt3(a, n);//操作3
    return 0;
}
