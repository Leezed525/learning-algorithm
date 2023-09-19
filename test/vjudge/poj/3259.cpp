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
const double PI = acos(-1);
const int MAXN = 5e2 + 10;
int n, m, w;
struct edge {
    int u, v, w;
    edge(int a, int b, int c) { u = a, v = b, w = c; }
};
vector<edge> g[MAXN];

bool spfa() {
    int dis[MAXN];
    bool vis[MAXN];
    int cnt[MAXN];
    memset(dis, INF, sizeof dis);
    memset(cnt, 0, sizeof cnt);
    memset(vis, 0, sizeof vis);
    dis[1] = 0;
    vis[1] = 1;
    cnt[1] = 1;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i].v;
            int w = g[u][i].w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!vis[v]) {
                    vis[v] = 1;
                    cnt[v]++;
                    if (cnt[v] > n) return true;
                    q.push(v);
                }
            }
        }
    }
    if (dis[1] < 0) return true;
    return false;
}

void init() {
    for (int i = 1; i <= n; i++) g[i].clear();
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> w;
        init();
        for (int i = 1; i <= m; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            g[a].push_back(edge(a, b, c));
            g[b].push_back(edge(b, a, c));
        }
        for (int i = 1; i <= w; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            g[a].push_back(edge(a, b, -c));
        }
        if (spfa())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    // system("pause");
    return 0;
}