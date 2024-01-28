#include<cstdio>
#include<stdio.h>

int a[100], b[100];

int main() {
    FILE *fp1 = fopen("a.dat", "r");
    FILE *fp2 = fopen("b.dat", "r");
    FILE *fp3 = fopen("c.dat", "w");
    int x, a_tot = 0, b_tot = 0;
    while (fscanf(fp1, "%d", &x) != EOF) {//读入a的数据
        a[++a_tot] = x;
    }
    while (fscanf(fp2, "%d", &x) != EOF) {//读入b的数据
        b[++b_tot] = x;
    }
    for (int i = 1; i <= a_tot; i++) {//判断a中元素是否在b中出现过
        bool flag = 1;//flag=1表示没出现过
        for (int j = 1; j <= b_tot; j++) {
            if (a[i] == b[j]) flag = 0;
        }
        if (flag) fprintf(fp3, "%d ", a[i]);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    return 0;
}
