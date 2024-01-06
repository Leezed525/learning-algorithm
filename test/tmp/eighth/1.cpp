//
// Created by Leezed on 2024/1/6.
//
#include<stdio.h>

typedef struct {
    float area;
    int students;
    char name[50];
} campus;

int main() {
    setbuf(stdout, NULL);
    campus a[4];
    for (int i = 0; i < 4; i += 1) {
        scanf("%s%f%d", a[i].name, &a[i].area, &a[i].students);
    }
    //找出学生最多的校区
    int max = 0;
    for (int i = 0; i < 4; i += 1) {
        if (a[i].students > a[max].students) {
            max = i;
        }
    }
    printf("学生最多的校区为:\n");
    printf("%s 占地%.2f亩  学生%d人\n", a[max].name,a[max].area, a[max].students );


    return 0;
}
/*
朝晖校区 414 3000
屏峰校区 2130 15000
莫干山校区 990 5000
之江校区 222 7500
 */