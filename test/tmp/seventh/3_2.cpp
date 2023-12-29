//
// Created by Leezed on 2023/12/25.
//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

const int MAXN = 3;

void divide_by_max_abs_in_row(float *arr, int len) {
    int row = len;
    int col = len;
    for (int i = 0; i < row; i++) {
        float max_abs = 0;
        for (int j = 0; j < col; j++) {
            if (fabs(*(arr + i * col + j)) > max_abs) {
                max_abs = fabs(*(arr + i * col + j));
            }
        }
        for (int j = 0; j < col; j++) {
            *(arr + i * col + j) /= max_abs;
        }
    }
}

int main() {
    int row = MAXN, col = MAXN;
    float arr[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] = (float) (i * col + j + 1);//生成数据
        }
    }
    divide_by_max_abs_in_row(arr[0], MAXN);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%.2f ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}