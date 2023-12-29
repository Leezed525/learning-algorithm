#include<stdio.h>

struct stu {
    char name[10];
    float score[4], sum;
};

void px(stu *);

void shuchu(stu);

int main() {
    stu a[10];
    int i, j;
    for (i = 0; i < 10; i++) {
        scanf("%s", a[i].name);
        a[i].sum = 0;
        for (j = 0; j < 4; j++) {
            scanf("%d", &a[i].score[j]);
            a[i].sum += a[i].score[j];
        }
    }
    px(a);
    for (i = 0; i < 10; i++)
        shuchu(a[i]);
}

void px(stu *p) {
    int i, j, k;
    stu temp;
    for (i = 0; i < 10; i++) {
        k = i;
        for (j = i + 1; j < 10; j++)
            if ((p + j)->sum > (p + k)->sum)
                k = j;
        temp = *(p + i);
        *(p + i) = *(p + k);
        *(p + k) = temp;
    }
}

void shuchu(stu a) {
    int i;
    printf("%s", a.name);
    for (i = 0; i < 4; i++)
        printf("%4d%4d", a.score[i], a.sum);
    printf("\n");
}