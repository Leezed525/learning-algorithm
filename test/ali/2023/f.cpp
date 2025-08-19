//
// Created by Leezed on 2025/8/19.
//
#include "bits/stdc++.h"

using namespace std;

const int maxn = 5e3 + 10;

map<int, int> rank_count;
map<int, int> rk;
vector<vector<int>> g = vector<vector<int>>(maxn, vector<int>());
int n;

int ans = INT_MAX;
int vis[maxn] = {0};

void bfs(int sx, int end_rank) {
    memset(vis, 0, sizeof(vis)); //清空访问数组
    queue<int> q;
    q.push(sx);
    vis[sx] = 1;
    int step = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i += 1) {
            int cur = q.front();
            q.pop();
            for (int next: g[cur]) {
                if (vis[next] == 0) { //如果这个点的排名不是唯一的
                    if (rk[next] == end_rank) {
                        ans = min(ans, step + 1);
                        return; //找到了一个符合条件的点
                    }
                    vis[next] = 1;
                    q.push(next);
                }
            }
        }
        step += 1;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i += 1) {
        int r;
        cin >> r;
        rank_count[r] += 1;
        rk[i + 1] = r;
    }
    for (int i = 1; i < n; i += 1) {
        int from, to;
        cin >> from >> to;
        g[from].push_back(to);
        g[to].push_back(from);
    }

    for (int i = 0; i < n; i += 1) {
        if (rank_count[rk[i + 1]] == 1) {
            continue; //如果这个点的排名是唯一的，则不需要考虑
        }
        bfs(i + 1, rk[i + 1]);
    }
    if (ans == INT_MAX) {
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;

}