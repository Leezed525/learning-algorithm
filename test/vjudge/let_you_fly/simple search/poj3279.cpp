//
// Created by Leezed on 2023/10/11.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int max_n = 20;
//记录原始地图
int origin[max_n][max_n];
//记录转换后的地图
int convert[max_n][max_n];
//记录操作地图
int oper[max_n][max_n];
int ans[max_n][max_n];
int min_ans = 0x3f3f3f3f;
int m, n;

bool check_convert() {
    for (int i = 1; i <= n; i += 1) {
        if (convert[m][i] == 1) {
            return false;
        }
    }
    return true;
}

int turn_count() {
    int ans = 0;
    for (int i = 1; i <= m; i += 1) {
        for (int j = 1; j <= n; j += 1) {
            if (oper[i][j] == 1) {
                ans += 1;
            }
        }
    }
    return ans;
}


int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i += 1) {
        for (int j = 1; j <= n; j += 1) {
            cin >> origin[i][j];
        }
    }
    for (int i = 0; i < (1 << n); i += 1) {
        memset(convert, 0, sizeof(convert));
        memset(oper, 0, sizeof(oper));
        for (int j = 1; j <= n; j += 1) {
            oper[1][j] = (i >> (n - j)) & 1;
        }
        for (int j = 1; j <= n; j += 1) {
            convert[1][j] = (origin[1][j] + oper[1][j] + oper[1][j - 1] + oper[1][j + 1]) % 2;
        }
        for (int j = 2; j <= m; j += 1) {
            for (int k = 1; k <= n; k += 1) {
                if (convert[j - 1][k] == 1) {
                    oper[j][k] = 1;
                }
            }
            for (int k = 1; k <= n; k += 1) {
                convert[j][k] = (origin[j][k] + oper[j][k] + oper[j][k - 1] + oper[j][k + 1] + oper[j - 1][k]) % 2;
            }
        }
        if (check_convert()) {
//            for(int j = 1;j <= m;j += 1){
//                for(int k = 1;k <= n;k += 1){
//                    cout << oper[j][k] << " ";
//                }
//                cout << endl;
//            }
            int count = turn_count();
            if (count < min_ans) {
                min_ans = count;
                memcpy(ans, oper, sizeof(oper));
            }
        }
    }
    if (min_ans != 0x3f3f3f3f) {
        for (int i = 1; i <= m; i += 1) {
            for (int j = 1; j <= n; j += 1) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}