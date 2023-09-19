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
const int MAXN = 1e5 + 10;
vector<int> g[MAXN];
int xing[MAXN];
int vis[MAXN];
int allflag;
void dfs(int u, int counts) {
    if (allflag) return;
    if (counts == 4) return;
    for (int i = 0; i < g[u].size(); i++) {
        if (vis[g[u][i]]) {
            allflag = 1;
            return;
        } else {
            vis[g[u][i]] = 1;
            dfs(g[u][i], counts + 1);
        }
    }
}

int main() {
    int n;
    cin >> n;
    memset(xing, -1, sizeof xing);
    for (int i = 1; i <= n; i++) {
        int child;
        scanf("%d", &child);
        getchar();
        char ch = getchar();
        if (ch == 'M')
            xing[child] = 1;
        else
            xing[child] = 0;
        int fa, ma;
        scanf("%d%d", &fa, &ma);
        if (fa != -1) xing[fa] = 1, g[child].push_back(fa);
        if (ma != -1) xing[ma] = 0, g[child].push_back(ma);
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (xing[a] == xing[b])
            cout << "Never Mind" << endl;
        else {
            memset(vis, 0, sizeof vis);
            allflag = 0;
            vis[a] = 1;
            vis[b] = 1;
            dfs(a, 0);
            dfs(b, 0);
            if (allflag)
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
    }
    // system("pause");
    return 0;
}