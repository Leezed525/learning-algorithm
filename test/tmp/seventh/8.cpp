//
// Created by Leezed on 2023/12/29.
//
#include<stdio.h>



typedef struct {
    char name[10];
    float score[4];
    float sum;
} student;

void sort(student *p, int len) {
    int i, j, k;
    student temp;
    for (i = 0; i < len; i++) {
        k = i;
        for (j = i + 1; j < len; j++)
            if ((p + j)->sum > (p + k)->sum)
                k = j;
        temp = *(p + i);
        *(p + i) = *(p + k);
        *(p + k) = temp;
    }
}

int main() {
    setbuf(stdout, NULL);
    student a[10];
    for (int i = 0; i < 10; i += 1) {
        scanf("%s", a[i].name);
        a[i].sum = 0;
        for (int j = 0; j < 4; j += 1) {
            scanf("%f", &a[i].score[j]);
            a[i].sum += a[i].score[j];
        }
    }
    sort(a, 10);
    for (int i = 0; i < 10; i += 1) {
        printf("%s ", a[i].name);
        for (int j = 0; j < 4; j += 1) {
            printf("%4.1f ", a[i].score[j]);
        }
        printf("sum: %4.1f\n", a[i].sum);
    }
    return 0;
}
/*
aaa 98 96 95 94
bbb 56 44 33 99
ccc 89 97 56 99
ddd 75 78 97 98
eee 88 88 89 87
fff 77 66 88 99
ggg 78 78 78 79
hhh 98 99 99 92
iii 78 78 79 79
jjj 94 94 94 96
*/

