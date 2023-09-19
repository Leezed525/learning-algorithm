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
int n, m, s, num = 0;
double V;

const int MAXN = 1e3 + 10;
int head[MAXN];
struct edge {
    int v, next;
    double c, k;
} a[MAXN];

void addedge(int u, int v, double c, double k) {
    a[++num].v = v;
    a[num].c = c;
    a[num].k = k;
    a[num].next = head[u];
    head[u] = num;
}

bool spfa() {
    bool vis[MAXN];
    int cnt[MAXN];
    double dis[MAXN];
    memset(vis, 0, sizeof vis);
    memset(cnt, 0, sizeof cnt);
    memset(dis, -INF, sizeof dis);
    cnt[s] = 1;
    dis[s] = V;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i != -1; i = a[i].next) {
            int v = a[i].v;
            double c = a[i].c;
            double k = a[i].k;
            double val = (dis[u] - c) * k;
            if (val > dis[v]) {
                dis[v] = val;
                if (!vis[v]) {
                    vis[v] = 1;
                    cnt[v]++;
                    if (cnt[v] > n) return true;
                    q.push(v);
                }
            }
        }
    }
    if (dis[s] > V) return true;
    return false;
}

int main() {
    cin >> n >> m >> s >> V;
    memset(head, -1, sizeof head);
    for (int i = 0; i < m; i++) {
        int a, b;
        double x1, y1, x2, y2;
        scanf("%d%d%lf%lf%lf%lf", &a, &b, &y1, &x1, &y2, &x2);
        addedge(a, b, x1, y1);
        addedge(b, a, x2, y2);
    }

    if (spfa())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    // system("pause");
    return 0;
}