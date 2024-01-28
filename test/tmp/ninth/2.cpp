#include<cstdio>
#include<stdio.h>

struct teacher {//老师结构体
    char name[100];
    int number, tim;
    char job[100];
} p;

int main() {
    int num;
    scanf("%d", &num);
    FILE *fp1 = fopen("teacher2.txt", "r");
    FILE *fp2 = fopen("teacher_temp.txt", "w");
    while (fscanf(fp1, "%s%d%d%s", p.name, &p.number, &p.tim, p.job) != EOF) {//依次读入数据
        if (p.number == num) continue;//遇到指定数据就不输出
        fprintf(fp2, "%s %d %d %s\n", p.name, p.number, p.tim, p.job);
    }
    fclose(fp1);
    fclose(fp2);
    remove("teacher2.txt");//删除原文件
    rename("teacher_temp.txt", "teacher2.txt");//改名
    return 0;
}
