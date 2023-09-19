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
int n;
const int MAXN = 26 + 5;
int mp[MAXN][MAXN];
int lowcost[MAXN], mst[MAXN];

int prim() {
    int res = 0;
    for (int i = 0; i < n; i++) {
        lowcost[i] = mp[0][i];
        mst[i] = 0;
    }
    mst[0] = -1;
    for (int i = 1; i < n; i++) {
        int minn = INF;
        int v = -1;
        for (int j = 1; j < n; j++) {
            if (mst[j] != -1 && lowcost[j] < minn) {
                minn = lowcost[j];
                v = j;
            }
        }
        if (v != -1) {
            res += minn;
            mst[v] = -1;
            for (int j = 1; j < n; j++) {
                if (mst[j] != -1 && mp[v][j] < lowcost[j]) {
                    lowcost[j] = mp[v][j];
                    mst[j] = v;
                }
            }
        }
    }
    return res;
}

int main() {
    while (cin >> n && n) {
        memset(mp, INF, sizeof mp);
        memset(lowcost, 0, sizeof lowcost);
        memset(mst, 0, sizeof mst);
        for (int i = 0; i < n - 1; i++) {
            char u;
            int m;
            scanf(" %c %d", &u, &m);
            for (int j = 0; j < m; j++) {
                char v;
                int w;
                scanf(" %c %d", &v, &w);
                mp[i][v - 'A'] = mp[v - 'A'][i] = w;
            }
        }
        cout << prim() << endl;
    }
    // system("pause");
    return 0;
}