//
// Created by Leezed on 2025/8/19.
//
#include "bits/stdc++.h"

using namespace std;

const int maxn = 55;
long long dp[maxn][maxn] = {0};

int main() {
    int n, m;
    cin >> n >> m;

    long long mod = 1e9 + 7;

    for (int i = 0; i <= m; i += 1) {
        dp[0][i] = 1; // 初始化第一列
    }

    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= m; j += 1) {
            for (int k = 0; k < i; k += 1) {
                long long tmp = (dp[k][j - 1] * dp[i - 1 - k][j - 1]) % mod;
                dp[i][j] = (dp[i][j] + tmp) % mod;
            }
        }
    }

//    for (int i = 0; i <= n; i += 1) {
//        for (int j = 0; j <= m; j += 1) {
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }


    cout << dp[n][m] << endl;


    return 0;
}
