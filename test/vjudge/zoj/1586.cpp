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
int lowcost[MAXN], mst[MAXN];
int value[MAXN];
int mp[MAXN][MAXN], n;

int prim() {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        mst[i] = 1;
        lowcost[i] = mp[1][i];
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
            for (int j = 1; j <= n; j++) {
                if (mst[j] != -1 && lowcost[j] > mp[v][j]) {
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
        memset(mp, INF, sizeof(mp));
        memset(lowcost, 0, sizeof lowcost);
        memset(mst, 0, sizeof mst);
        memset(value, 0, sizeof(value));
        cin >> n;
        for (int i = 1; i <= n; i++) scanf("%d", &value[i]);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%d", &mp[i][j]);
                if (i == j) continue;
                mp[i][j] += value[i] + value[j];
            }
        }
        cout << prim() << endl;
    }
    // system("pause");
    return 0;
}