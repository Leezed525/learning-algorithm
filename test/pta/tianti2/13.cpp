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
const int MAXN = 510;
int tpre[MAXN], lpre[MAXN];
int n, m;
int start, goal;
struct node {
    int u, v, w;
    node(int a, int b, int c) {
        u = a;
        v = b;
        w = c;
    }
};
vector<node> tg[MAXN], lg[MAXN];

struct snode {
    int id, dis;
    snode(int a, int b) {
        id = a;
        dis = b;
    }
    bool operator<(const snode &t) const { return dis < t.dis; }
};

void printpath() {}
int tdijkstra() {
    int s = start;
    int dis[MAXN];
    bool vis[MAXN];
    for (int i = 0; i < n; i++) {
        dis[i] = INF;
        vis[i] = false;
    }
    dis[start] = 0;
    priority_queue<snode> q;
    q.push(snode(start, 0));
    while (!q.empty()) {
        snode u = q.top();
        q.pop();
        if (vis[u.id]) continue;
        vis[u.id] = 1;
        for (int i = 0; i < tg[u.id].size(); i++) {
            node y = tg[u.id][i];
            if (vis[y.v]) continue;
            if (dis[y.v] > u.dis + y.w) {
                dis[y.v] = u.dis + y.w;
                q.push(snode(y.v, dis[y.v]));
                tpre[y.v] = u.id;
            }
        }
    }
    return dis[goal];
}

int ldijkstra() {
    int s = start;
    int dis[MAXN];
    bool vis[MAXN];
    for (int i = 0; i < n; i++) {
        dis[i] = INF;
        vis[i] = false;
    }
    dis[start] = 0;
    priority_queue<snode> q;
    q.push(snode(start, 0));
    while (!q.empty()) {
        snode u = q.top();
        q.pop();
        if (vis[u.id]) continue;
        vis[u.id] = 1;
        for (int i = 0; i < lg[u.id].size(); i++) {
            node y = tg[u.id][i];
            if (vis[y.v]) continue;
            if (dis[y.v] > u.dis + y.w) {
                dis[y.v] = u.dis + y.w;
                q.push(snode(y.v, dis[y.v]));
                lpre[y.v] = y.u;
            }
        }
    }
    return dis[goal];
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int oneway, length, time, u, v;
        scanf("%d%d%d%d%d", &u, &v, &oneway, &length, &time);
        if (oneway) {
            tg[u].push_back(node(u, v, time));
            lg[u].push_back(node(u, v, length));
        } else {
            tg[u].push_back(node(u, v, time));
            tg[v].push_back(node(v, u, time));
            lg[u].push_back(node(u, v, length));
            lg[v].push_back(node(v, u, length));
        }
    }
    cin >> start >> goal;
    int tans = tdijkstra();
    int lans = ldijkstra();
    cout << tans << endl << lans << endl;
    // system("pause");
    return 0;
}