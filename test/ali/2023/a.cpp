//
// Created by Leezed on 2025/8/18.
//
#include "bits/stdc++.h"

using namespace std;

const int maxn = 1e5 + 10;


struct item {
    int x, y;

    item() : x(0), y(0) {}
};

bool cmp(item a, item b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y > b.y;
}


item a[maxn];


int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i += 1) {
            cin >> a[i].x;
        }
        for (int i = 0; i < n; i += 1) {
            cin >> a[i].y;
        }

        sort(a, a + n, cmp);
        int dp[maxn] = {0};
        int ans = 0;
        //dp 最长上升子序列或者最长下降子序列
//        for (int i = 0; i < n; i += 1) {
//            dp[i] = 1;
//            for (int j = 0; j < i; j += 1) {
//                if (a[i].y > a[j].y) {
//                    dp[i] = max(dp[i], dp[j] + 1);
//                }
//            }
//            ans = max(ans, dp[i]);
//        }

        vector<int> arr;
        for (int i = 0; i < n; i += 1) {
            if (arr.size() == 0 || a[i].y > arr.back()) {
                arr.push_back(a[i].y);
            } else {
                auto it = lower_bound(arr.begin(), arr.end(), a[i].y);
                *it = a[i].y; // 替换掉第一个大于等于a[i].y的数
            }
        }
        cout << arr.size() << endl;
//        cout << ans << endl;
    }
}