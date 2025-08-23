//
// Created by Leezed on 2025/8/23.
//
#include "bits/stdc++.h"

using namespace std;

const int maxn = 2e5 + 10;

vector<map<int, long long>> contact = vector<map<int, long long>>(maxn);
int n, q;
vector<int> red = vector<int>(maxn, 0);
vector<int> fa = vector<int>(maxn, 0);
vector<int> vis = vector<int>(maxn, 0);
unordered_set<int> red_set;


map<int, long long> build_tree(int x) {
    map<int, long long> child;
    vis[x] = 1;
    for (auto it: contact[x]) {
        if (vis[it.first]) {
            continue;
        }
        int to = it.first;
        long long w = it.second;
        fa[to] = x;//记录父节点
        child[to] = w;
        auto tmp = build_tree(to);
        for (auto t: tmp) {
            child[t.first] = t.second + w;
        }
    }
    contact[x] = child; //更新当前节点的子节点
    return child;
}


long long get_edge(int from, int to) {
    if (from == to) {
        return 0;
    }
    if (contact[from].find(to) != contact[from].end()) {
        return contact[from][to];
    }
    return contact[fa[from]][from] + get_edge(fa[from], to);
}


void debug_tree() {
    for (int i = 1; i <= n; i += 1) {
        cout << "Node " << i << ": ";
        for (auto it: contact[i]) {
            cout << "(" << it.first << ", " << it.second << ") ";
        }
        cout << endl;
    }

    //输出父亲节点

    for (int i = 1; i <= n; i += 1) {
        cout << "fa[" << i << "] = " << fa[i] << endl;
    }

    cout << get_edge(4, 5) << endl;
}


int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i += 1) {
        int x;
        cin >> x;
        red[i] = x;
        if (x == 1) {
            red_set.insert(i);
        }
    }
    for (int i = 1; i < n; i += 1) {
        int from, to;
        long long w;
        cin >> from >> to >> w;
        contact[from][to] = w;
        contact[to][from] = w;
    }
    build_tree(1);
//    debug_tree();
    for (int i = 0; i < q; i += 1) {
        int q_num, ops;
        cin >> q_num >> ops;
        if (q_num == 1) {
            if (red[ops] == 1) {
                red_set.erase(ops);
                red[ops] = 0;
            } else {
                red_set.insert(ops);
                red[ops] = 1;
            }
        } else {
            int from = ops;
            long long ans = 0;
            for (auto it: red_set) {
                if (it == from) {
                    continue;
                }
                if (red[it] == 0) {
                    continue;
                }
                ans += get_edge(from, it);
            }
            cout << ans << endl;
        }
    }
}
/*
7 5
1 0 1 0 1 0 0
1 2 1
1 3 2
3 4 3
3 5 4
4 6 1
4 7 1
2 1
2 2
1 3
2 2
2 2



*/