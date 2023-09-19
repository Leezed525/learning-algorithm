#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
//*(int(*)[10])arr_name
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 1e+4 + 10;
vector<int> ma[maxn];
typedef pair<int, int> P;
int vis[maxn];
int ans;
int ansi;
int bfs(int t) {
    int s;
    queue<P> que;
    que.push(P(t, 0));
    ans = 0;
    ansi = t;
    vis[t] = 1;
    while (!que.empty()) {
        P tmp = que.front();
        int x = tmp.first;
        int y = tmp.second;
        que.pop();
        if (ans == y) {
            ansi = min(ansi, x);
        }
        if (ans < y) {
            ans = y;
            ansi = x;
        }
        for (int i = 0; i < ma[x].size(); i++) {
            if (!vis[ma[x][i]]) {
                que.push(P(ma[x][i], y + 1));
                vis[ma[x][i]] = 1;
            }
        }
    }
    if (ans == 0) return 0;
    return ansi;
}
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        ma[a].push_back(b);
        ma[b].push_back(a);
    }

    for (int i = 0; i < k; i++) {
        int tar;
        scanf("%d", &tar);
        memset(vis, 0, sizeof(vis));
        ans = 0;
        ansi = 0;
        ansi = bfs(tar);
        cout << ansi << endl;
    }
    return 0;
}