
#include<stdio.h>
#include<stdlib.h>

void month_day(int year, int yearday, int *pmonth, int *pday) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        if (1 <= yearday && yearday <= 31) {
            *pmonth = 1;
            *pday = yearday;
        }
        if (32 <= yearday && yearday <= 60) {
            *pmonth = 2;
            *pday = yearday - 31;
        }
        if (61 <= yearday && yearday <= 91) {
            *pmonth = 3;
            *pday = yearday - 31 - 29;
        }
        if (92 <= yearday && yearday <= 121) {
            *pmonth = 4;
            *pday = yearday - 31 - 29 - 31;
        }
        if (122 <= yearday && yearday <= 152) {
            *pmonth = 5;
            *pday = yearday - 31 - 29 - 31 - 30;
        }
        if (153 <= yearday && yearday <= 182) {
            *pmonth = 6;
            *pday = yearday - 31 - 29 - 31 - 30 - 31;
        }
        if (183 <= yearday && yearday <= 213) {
            *pmonth = 7;
            *pday = yearday - 31 - 29 - 31 - 30 - 31 - 30;
        }
        if (214 <= yearday && yearday <= 244) {
            *pmonth = 8;
            *pday = yearday - 31 - 29 - 31 - 30 - 31 - 30 - 31;
        }
        if (245 <= yearday && yearday <= 274) {
            *pmonth = 9;
            *pday = yearday - 31 - 29 - 31 - 30 - 31 - 30 - 31 - 31;
        }
        if (275 <= yearday && yearday <= 305) {
            *pmonth = 10;
            *pday = yearday - 31 - 29 - 31 - 30 - 31 - 30 - 31 - 31 - 30;
        }
        if (306 <= yearday && yearday <= 335) {
            *pmonth = 11;
            *pday = yearday - 31 - 29 - 31 - 30 - 31 - 30 - 31 - 31 - 30 - 31;
        }
        if (336 <= yearday && yearday <= 366) {
            *pmonth = 12;
            *pday = yearday - 31 - 29 - 31 - 30 - 31 - 30 - 31 - 31 - 30 - 31 - 30;
        }
    } else {
        if (1 <= yearday && yearday <= 31) {
            *pmonth = 1;
            *pday = yearday;
        }
        if (32 <= yearday && yearday <= 59) {
            *pmonth = 2;
            *pday = yearday - 31;
        }
        if (60 <= yearday && yearday <= 90) {
            *pmonth = 3;
            *pday = yearday - 31 - 28;
        }
        if (91 <= yearday && yearday <= 120) {
            *pmonth = 4;
            *pday = yearday - 31 - 28 - 31;
        }
        if (121 <= yearday && yearday <= 151) {
            *pmonth = 5;
            *pday = yearday - 31 - 28 - 31 - 30;
        }
        if (152 <= yearday && yearday <= 181) {
            *pmonth = 6;
            *pday = yearday - 31 - 28 - 31 - 30 - 31;
        }
        if (182 <= yearday && yearday <= 212) {
            *pmonth = 7;
            *pday = yearday - 31 - 28 - 31 - 30 - 31 - 30;
        }
        if (213 <= yearday && yearday <= 243) {
            *pmonth = 8;
            *pday = yearday - 31 - 28 - 31 - 30 - 31 - 30 - 31;
        }
        if (244 <= yearday && yearday <= 273) {
            *pmonth = 9;
            *pday = yearday - 31 - 28 - 31 - 30 - 31 - 30 - 31 - 31;
        }
        if (274 <= yearday && yearday <= 304) {
            *pmonth = 10;
            *pday = yearday - 31 - 28 - 31 - 30 - 31 - 30 - 31 - 31 - 30;
        }
        if (305 <= yearday && yearday <= 335) {
            *pmonth = 11;
            *pday = yearday - 31 - 28 - 31 - 30 - 31 - 30 - 31 - 31 - 30 - 31;
        }
        if (336 <= yearday && yearday <= 365) {
            *pmonth = 12;
            *pday = yearday - 31 - 28 - 31 - 30 - 31 - 30 - 31 - 31 - 30 - 31 - 30;
        }
    }

}

int main() {
    int year, yearday;
    int *pmonth = (int *) malloc(1 * sizeof(int)), *pday = (int *) malloc(1 * sizeof(int));
    scanf("%d %d", &year, &yearday);
    month_day(year, yearday, pmonth, pday);
    printf("%d-%d-%d", year, *pmonth, *pday);
}

