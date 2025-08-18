//
// Created by Leezed on 2025/8/15.
//
#include "iostream"
#include "vector"
#include "map"
#include "algorithm"

using namespace std;

int maxn = 1e3 + 10;

vector<vector<int>> g = vector<vector<int>>(maxn, vector<int>());

vector<int> color = vector<int>(maxn, 0);
vector<int> in = vector<int>(maxn, 0);
vector<int> vis = vector<int>(maxn, 0);
vector<map<int, int>> restore = vector<map<int, int>>(maxn, map<int, int>());

int n;

int ans = 0;


bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}


int compute_result(map<int, int> mp) {
    vector<pair<int, int>> vals = vector<pair<int, int>>();
    for (auto &it: mp) {
        vals.emplace_back(it.first, it.second);
    }

    sort(vals.begin(), vals.end(), cmp);
    int max_val = vals[vals.size() - 1].second;
    int end = vals.size() - 2;
    while (end >= 0 && vals[end].second == max_val) {
        end -= 1;
    }
    int res = 0;
    for (int i = 0; i <= end; i += 1) {
        if (vals[i].second % 2 == 1) {
            res ^= vals[i].first;
        }
    }

    return res;
}

map<int, int> dfs(int cur, int pre) {

    map<int, int> mp;
    if (g[cur].size() == 0) {
        mp[color[cur]] = 1;
        return mp;
    }

    for (int i = 0; i < g[cur].size(); i += 1) {
        int next = g[cur][i];
        if (next == pre) continue;
        map<int, int> nextMap = dfs(next, cur);
        for (auto &it: nextMap) {
            mp[it.first] += it.second;
        }
    }

    mp[color[cur]] += 1;

    ans = max(ans, compute_result(mp));

    return mp;

}


int main() {
    cin >> n;
    for (int i = 1; i <= n; i += 1) {
        cin >> color[i];
    }

    for (int i = 0; i < n - 1; i += 1) {
        int from, to;
        cin >> from >> to;
        g[from].push_back(to);
        g[to].push_back(from);
    }

    dfs(1, 0);
    cout << ans << endl;

    return 0;
}