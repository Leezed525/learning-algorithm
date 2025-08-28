//
// Created by Leezed on 2025/8/26.
//
#include "bits/stdc++.h"

using namespace std;

int n, m;

vector<int> path;

void dfs(int cur) {
    if (path.size() == m) {
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << (i == path.size() - 1 ? '\n' : ' ');
        }
        return;
    }

    for (int i = cur; i <= n; i += 1) {
        path.push_back(i);
        dfs(i + 1);
        path.pop_back();
    }
}

int main() {
    cin >> n >> m;
    dfs(1);
    return 0;
}