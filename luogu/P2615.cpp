#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n + 1][n + 1];
    int r[n * n + 1];
    int c[n * n + 1];
    for (int i = 0; i <= n; i += 1) {
        for (int j = 0; j <= n; j += 1) {
            a[i][j] = 0;
        }
    }
    for (int i = 0; i <= n * n; i += 1) {
        r[i] = 0;
        c[i] = 0;
    }
    a[1][(n + 1) / 2] = 1;
    r[1] = 1;
    c[1] = (n + 1) / 2;
    int x = 2;
    while (x <= n * n) {
        int k = x - 1;
        if (r[k] == 1 && c[k] != n) {
            a[n][c[k] + 1] = x;
            r[x] = n;
            c[x] = c[k] + 1;
        } else if (r[k] != 1 && c[k] == n) {
            a[r[k] - 1][1] = x;
            r[x] = r[k] - 1;
            c[x] = 1;
        } else if (r[k] == 1 && c[k] == n) {
            a[r[k] + 1][c[k]] = x;
            r[x] = r[k] + 1;
            c[x] = c[k];
        } else {
            if (a[r[k] - 1][c[k] + 1] == 0) {
                a[r[k] - 1][c[k] + 1] = x;
                r[x] = r[k] - 1;
                c[x] = c[k] + 1;
            } else {
                a[r[k] + 1][c[k]] = x;
                r[x] = r[k] + 1;
                c[x] = c[k];
            }
        }
        x += 1;
    }
    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= n; j += 1) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    // system("pause");
    return 0;
}