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
int n, m, cas = 1;
int mp[MAXN][MAXN];

void dijkstra() {
    int dis[MAXN];
    bool vis[MAXN];
    for (int i = 2; i <= n; i++) {
        dis[i] = mp[1][i];
        vis[i] = 0;
    }
    dis[1] = 0;
    vis[1] = 1;
    for (int i = 1; i < n; i++) {
        int maxn = -INF, flag = 1;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && dis[j] > maxn) {
                maxn = dis[j];
                flag = j;
            }
        }
        vis[flag] = 1;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && min(dis[flag], mp[flag][j]) > dis[j]) {
                dis[j] = min(dis[flag], mp[flag][j]);
            }
        }
    }
    printf("Scenario #%d:\n%d\n\n", cas++, dis[n]);
}

int main() {
    int T, cas = 1;
    cin >> T;
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) mp[i][j] = -INF;
        for (int i = 1; i <= m; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            mp[a][b] = mp[b][a] = c;
        }
        dijkstra();
    }
    // system("pause");
    return 0;
}