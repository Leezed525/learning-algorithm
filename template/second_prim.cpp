#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1000 + 10, INF = 0x3f3f3f3f;
int n, m, lowc[maxn], pre[maxn], Max[maxn][maxn], cost[maxn][maxn];
bool vis[maxn], used[maxn][maxn];

int Prim() {
    int ans = 0;
    memset(vis, false, sizeof vis);
    memset(Max, 0, sizeof Max);
    memset(used, false, sizeof used);
    vis[1] = true;
    pre[1] = -1;
    for (int i = 2; i <= n; i++) {
        lowc[i] = cost[1][i];
        pre[i] = 1;
    }
    lowc[1] = 0;
    for (int i = 2; i <= n; i++) {
        int MIN = INF, p = -1;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && MIN > lowc[j]) {
                MIN = lowc[j];
                p = j;
            }
        }
        if (MIN == INF) return -1;
        ans += MIN;
        vis[p] = true;
        used[p][pre[p]] = used[pre[p]][p] = true;
        for (int j = 1; j <= n; j++) {
            if (vis[j] && j != p) Max[j][p] = Max[p][j] = max(Max[j][pre[p]], lowc[p]);//找的加一条边后环的最大边
            if (!vis[j] && lowc[j] > cost[p][j]) {
                lowc[j] = cost[p][j];
                pre[j] = p;
            }
        }
    }
    return ans;
}

int Second_Prim(int MST) {
    int ans = INF;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (!used[i][j] && cost[i][j] != INF) ans = min(ans, MST - Max[i][j] + cost[i][j]);
    return ans;
}

int main() {
    int t, a, b, c;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++) cost[i][j] = INF;
        for (int i = 1; i <= m; i++) {
            scanf("%d %d %d", &a, &b, &c);
            cost[a][b] = cost[b][a] = c;
        }
        int MST = Prim();
        int Second_MST = Second_Prim(MST);
        printf("%d\n", Second_MST);
    }
    return 0;
}