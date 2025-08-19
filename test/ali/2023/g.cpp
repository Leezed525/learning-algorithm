//
// Created by Leezed on 2025/8/19.
//
#include "bits/stdc++.h"

using namespace std;

const int maxn = 1e4 + 10;

struct item {
    int need;
    int count;

    item(int need, int count) : need(need), count(count) {}
};


int a[maxn];
int vis[maxn] = {0};


int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i += 1) {
        cin >> a[i];
    }
    int k;
    cin >> k;
    vector<item> items;

    for (int i = 0; i < k; i += 1) {
        int niuniua, niuniub;
        cin >> niuniua >> niuniub;
        items.emplace_back(a[niuniua] + a[niuniub], 2);
        vis[niuniua] = 1;
        vis[niuniub] = 1;
    }

    for (int i = 1; i <= n; i += 1) {
        if (vis[i] == 0) {
            items.emplace_back(a[i], 1);
        }
    }

    int dp[maxn] = {0};

    for (int i = 0; i < items.size(); i += 1) {
        for (int j = m; j >= items[i].need; j -= 1) {
            dp[j] = max(dp[j], dp[j - items[i].need] + items[i].count);
        }
    }
    cout << dp[m] << endl;

    return 0;
}