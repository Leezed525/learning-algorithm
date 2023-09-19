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
#define ms(x, n) memset(x, n, sizeof(x));
using namespace std;
//*(int(*)[10])arr_name
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
const int MAXN = 15000 + 10;

int n, m;
struct edge {
    int u, t, w;
    edge(int a, int b, int c) {
        u = a;
        t = b;
        w = c;
    }
};

struct snode {
    int id;
    int dis;
    snode(int a, int b) {
        id = a;
        dis = b;
    }
    bool operator<(const snode &t) const { return dis > t.dis; }
};

vector<edge> g[MAXN];
int dis[MAXN];
int vis[MAXN];
void dijkstra() {
    priority_queue<snode> q;
    for(int i = 1;i <= n;i++){
        dis[i] = 0;
    }
    q.push(snode(1, 0));
    while (!q.empty()) {
        snode u = q.top();
        q.pop();
        //if (vis[u.id]) continue;
        //vis[u.id] = 1;
        for (int i = 0; i < g[u.id].size(); i++) {
            edge y = g[u.id][i];
            //if (vis[y.t]) continue;
            if (dis[y.t] < y.w + dis[y.u]) {
                dis[y.t] = y.w + dis[y.u];
                q.push(snode(y.t, dis[y.t]));
            }
        }
    }
    if (!dis[n])
        printf("-1");
    else
        printf("%d", dis[n]);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a].push_back(edge(a, b, c));
        //g[b].push_back(edge(b, a, c));
    }
    dijkstra();
    // system("pause");
    return 0;
}