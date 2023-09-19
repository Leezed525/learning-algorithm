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
const int MAXN = 1e3 + 10;
int x[MAXN], y[MAXN], p[MAXN];
double mp[MAXN][MAXN], maxd[MAXN][MAXN], lowcost[MAXN], B;
bool used[MAXN][MAXN], vis[MAXN];
int n, pre[MAXN];

void init() {
    ms(vis, 0);
    ms(pre, -1);
    ms(used, 0);
    ms(maxd, 0);
}

double getlen(int i, int j) {
    int x1 = x[i] - x[j];
    int y1 = y[i] - y[j];
    return sqrt(x1 * x1 + y1 * y1);
}

void prim() {
    double res = 0;
    for (int i = 2; i <= n; i++) {
        lowcost[i] = mp[1][i];
        pre[i] = 1;
    }
    vis[1] = 1;
    pre[1] = -1;
    lowcost[1] = 0;
    for (int i = 1; i < n; i++) {
        double minn = INF;
        int v = -1;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && lowcost[j] < minn) {
                minn = lowcost[j];
                v = j;
            }
        }
        if (v != -1) {
            res += minn;
            used[v][pre[v]] = used[pre[v]][v] = 1;
            vis[v] = 1;
            for (int j = 1; j <= n; j++) {
                if (vis[j] && j != v) maxd[j][v] = maxd[v][j] = max(maxd[j][pre[v]], lowcost[v]);
                if (!vis[j] && lowcost[j] > mp[v][j]) {
                    lowcost[j] = mp[v][j];
                    pre[j] = v;
                }
            }
        }
    }
    B = res;
    return;
}

void second_prim() {
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            double A = p[i] + p[j];
            if (!used[i][j])
                ans = max(ans, A / (B - maxd[i][j]));
            else
                ans = max(ans, A / (B - mp[i][j]));
        }
    }
    printf("%.2lf\n", ans);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        init();
        for (int i = 1; i <= n; i++) scanf("%d%d%d", &x[i], &y[i], &p[i]);
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                mp[i][j] = mp[j][i] = getlen(i, j);
            }
        }
        prim();
        second_prim();
    }
    // system("pause");
    return 0;
}