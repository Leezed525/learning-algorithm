//
// Created by Leezed on 2025/8/27.
//
#include "bits/stdc++.h"


using namespace std;

const int maxn = 2e5 + 10;

int f[maxn];
int n;

void init() {
    for (int i = 1; i <= n; i += 1) {
        f[i] = i;
    }
}

int get(int x) {
    return f[x] == x ? x : f[x] = get(f[x]);
}

void merge(int from, int to) {
    int fx = get(from);
    int fy = get(to);
    if (fx != fy) {
        f[fx] = fy;
    }
}


int main() {
    cin >> n;
    init();
    for (int i = 1; i <= n; i += 1) {
        int tmp;
        cin >> tmp;
        if (tmp != 0) {
            merge(i, tmp);
        }
    }

    map<int, int> mp;
    for (int i = 1; i <= n; i += 1) {
        int fx = get(i);
        mp[fx]++;
    }

    vector<int> ans(n);
    for (int i = 1; i <= n; i += 1) {
        ans[i] = mp[i] == 0 ? 1 : mp[i];
        cout << ans[i] << (i == n ? '\n' : ' ');
    }


    return 0;

}