//
// Created by Leezed on 2025/8/19.
//
#include "bits/stdc++.h"

using namespace std;

const int maxn = 110;

int mod = 10000;


int mp[maxn][maxn];

int dp[maxn][maxn] = {0};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        memset(dp, 0, sizeof(dp));
        memset(mp, 0, sizeof(mp));
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                cin >> mp[i][j];
            }
        }
        dp[0][0] = 1;

        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                int step = mp[i][j];
                for (int k = 1; k <= step; k += 1) {
                    for (int ni = 0; ni <= k; ni += 1) {
                        int nx = i + ni;
                        int ny = j + k - ni;
                        if (nx < n && ny < m) {
                            dp[nx][ny] = (dp[nx][ny] + dp[i][j]) % mod;
                        }
                    }
                }
            }
        }

//        for (int i = 0; i < n; i += 1) {
//            for (int j = 0; j < m; j += 1) {
//                cout << dp[i][j] << " ";
//            }
//            cout << endl;
//        }

        cout << dp[n - 1][m - 1] << endl;

    }
    return 0;
}