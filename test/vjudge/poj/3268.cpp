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
const int MAXN = 1e3 + 10;
int n, m, s;
struct edge {
    int u, t, w;
    edge(int a, int b, int c) { u = a, t = b, w = c; }
};
vector<edge> g[MAXN], g1[MAXN];
struct snode {
    int id, dis;
    snode(int a, int b) { id = a, dis = b; }
    bool operator<(const snode &t) const { return dis > t.dis; }
};
int dis[MAXN], dis1[MAXN];

void dijkstra1() {
    bool vis[MAXN];
    for (int i = 1; i <= n; i++) {
        dis1[i] = INF;
        vis[i] = 0;
    }
    dis1[s] = 0;
    priority_queue<snode> q;
    q.push(snode(s, 0));
    while (!q.empty()) {
        snode tmp = q.top();
        q.pop();
        if (vis[tmp.id]) continue;
        vis[tmp.id] = 1;
        for (int i = 0; i < g1[tmp.id].size(); i++) {
            edge y = g1[tmp.id][i];
            if (!vis[y.t] && dis1[y.u] + y.w < dis1[y.t]) {
                dis1[y.t] = dis1[y.u] + y.w;
            }
            q.push(snode(y.t, dis1[y.t]));
        }
    }
    int maxn = -1;
    for (int i = 1; i <= n; i++) {
        maxn = max(maxn, dis[i] + dis1[i]);
    }
    cout << maxn << endl;
}

void dijkstra() {
    bool vis[MAXN];
    for (int i = 1; i <= n; i++) {
        dis[i] = INF;
        vis[i] = 0;
    }
    dis[s] = 0;
    priority_queue<snode> q;
    q.push(snode(s, 0));
    while (!q.empty()) {
        snode tmp = q.top();
        q.pop();
        if (vis[tmp.id]) continue;
        vis[tmp.id] = 1;
        for (int i = 0; i < g[tmp.id].size(); i++) {
            edge y = g[tmp.id][i];
            if (!vis[y.t] && dis[y.u] + y.w < dis[y.t]) {
                dis[y.t] = dis[y.u] + y.w;
            }
            q.push(snode(y.t, dis[y.t]));
        }
    }
    dijkstra1();
}

int main() {
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[b].push_back(edge(b, a, c));
        g1[a].push_back(edge(a, b, c));
    }
    dijkstra();
    // system("pause");
    return 0;
}
