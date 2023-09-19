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
const int MAXN = 1e2 + 10;
int lowcost[MAXN], mst[MAXN];
int mp[MAXN][MAXN], n, m;

int prim() {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        lowcost[i] = mp[1][i];
        mst[i] = 1;
    }
    mst[1] = -1;
    for (int i = 1; i < n; i++) {
        int minn = INF;
        int v = -1;
        for (int j = 1; j <= n; j++) {
            if (mst[j] != -1 && lowcost[j] < minn) {
                minn = lowcost[j];
                v = j;
            }
        }

        if (v != -1) {
            res += minn;
            mst[v] = -1;
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                if (mst[j] == -1) {
                    if (mp[j][v] == minn) cnt++;
                    if (cnt > 1) return -1;
                } else if (lowcost[j] > mp[v][j]) {
                    lowcost[j] = mp[v][j];
                    mst[j] = v;
                }
            }
        }
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        memset(mp, INF, sizeof mp);
        memset(lowcost, 0, sizeof lowcost);
        memset(mst, 0, sizeof mst);
        for (int i = 1; i <= m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            mp[u][v] = mp[v][u] = min(mp[u][v], w);
        }
        int ans = prim();
        if (ans == -1)
            cout << "Not Unique!" << endl;
        else
            cout << ans << endl;
    }
    // system("pause");
    return 0;
}