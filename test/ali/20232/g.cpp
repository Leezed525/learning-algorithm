//
// Created by Leezed on 2025/8/27.
//
#include "bits/stdc++.h"

using namespace std;

const int maxn = 1e5 + 10;

int a[3][maxn];

long long dp[3][maxn];

int main() {

    int n;
    cin >> n;
    for (int i = 0; i < 3; i += 1) {
        for (int j = 0; j < n; j += 1) {
            cin >> a[i][j];
        }
    }
    dp[0][0] = dp[1][0] = dp[2][0] = 0;

    for (int i = 0; i < n - 1; i += 1) {
        dp[0][i + 1] = min(dp[0][i] + abs(a[0][i + 1] - a[0][i]),
                           min(dp[1][i] + abs(a[0][i + 1] - a[1][i]),
                               dp[2][i] + abs(a[0][i + 1] - a[2][i])));
        dp[1][i + 1] = min(dp[0][i] + abs(a[1][i + 1] - a[0][i]),
                           min(dp[1][i] + abs(a[1][i + 1] - a[1][i]),
                               dp[2][i] + abs(a[1][i + 1] - a[2][i])));
        dp[2][i + 1] = min(dp[0][i] + abs(a[2][i + 1] - a[0][i]),
                           min(dp[1][i] + abs(a[2][i + 1] - a[1][i]),
                               dp[2][i] + abs(a[2][i + 1] - a[2][i])));
    }


    cout << min({ dp[0][n - 1], dp[1][n - 1], dp[2][n - 1] }) << endl;


    return 0;
}