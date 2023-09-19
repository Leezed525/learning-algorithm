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
const int MAXN = 1e5 + 10;
vector<int> g[MAXN];
int n, m;
int vis[MAXN];

void dfs(int start) {
    vis[start] = 1;
    printf("%d ", start);
    for (int i = 0; i < g[start].size(); i++) {
        if (!vis[g[start][i]]) dfs(g[start][i]);
    }
    return;
}

void bfs() {
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty()) {
        int x = q.front();
        vis[x] = 1;
        q.pop();
        printf("%d ", x);
        for (int i = 0; i < g[x].size(); i++) {
            if (!vis[g[x][i]]) q.push(g[x][i]), vis[g[x][i]] = 1;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end());

    ms(vis, 0);
    dfs(1);
    printf("\n");
    ms(vis, 0);
    bfs();
    // system("pause");
    return 0;
}