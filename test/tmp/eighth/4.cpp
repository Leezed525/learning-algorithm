//
// Created by Leezed on 2024/1/6.
//
#include<stdio.h>

typedef struct {
    int year, month, day;
} Date;

typedef struct {
    char name[50];
    char code[50];
    Date birthday;
    Date workday;
    char title[50];
} Teacher;

bool cmp_by_age(Teacher a, Teacher b) {
    if (a.birthday.year != b.birthday.year) {
        return a.birthday.year > b.birthday.year;
    } else if (a.birthday.month != b.birthday.month) {
        return a.birthday.month > b.birthday.month;
    } else {
        return a.birthday.day > b.birthday.day;
    }
}

void sort_by_age(Teacher *a, int n) {
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n - i - 1; j += 1) {
            if (cmp_by_age(a[j], a[j + 1])) {
                Teacher temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void output_all(Teacher *a, int n) {

    printf("按照年龄排序的输出：\n");
    for (int i = 0; i < n; i += 1) {
        printf("%s %s %d-%d-%d %d-%d-%d %s\n", a[i].name, a[i].code, a[i].birthday.year, a[i].birthday.month,
               a[i].birthday.day, a[i].workday.year, a[i].workday.month, a[i].workday.day, a[i].title);
    }
}

void output_work_after_2005(Teacher *a, int n) {
    printf("\n在2005年之后参加工作的老师有：\n");

    for (int i = 0; i < n; i += 1) {
        if (a[i].workday.year >= 2005) {
            printf("%s %s %d-%d-%d %d-%d-%d %s\n", a[i].name, a[i].code, a[i].birthday.year, a[i].birthday.month,
                   a[i].birthday.day, a[i].workday.year, a[i].workday.month, a[i].workday.day, a[i].title);
        }
    }
    printf("\n\n");
}

int main() {
    setbuf(stdout, NULL);
    Teacher a[5];
    for (int i = 0; i < 5; i += 1) {
        scanf("%s", a[i].name);
        scanf("%s", a[i].code);
        Date tmp_birthday, tmp_workday;
        scanf("%d-%d-%d", &tmp_birthday.year, &tmp_birthday.month, &tmp_birthday.day);
        scanf("%d-%d-%d", &tmp_workday.year, &tmp_workday.month, &tmp_workday.day);
        scanf("%s", a[i].title);
        a[i].birthday = tmp_birthday;
        a[i].workday = tmp_workday;
    }

    sort_by_age(a, 5);

    output_work_after_2005(a, 5);

    output_all(a, 5);

    return 0;
}
/*
张三 zjut001 1970-1-1 2000-1-1 教授
李四 zjut002 1995-1-1 2015-1-1 副教授
王五 zjut003 1998-1-1 2018-1-1 讲师
赵六 zjut004 2000-1-1 2020-1-1 助教
李七 zjut005 2005-1-1 2025-1-1 教授
 */