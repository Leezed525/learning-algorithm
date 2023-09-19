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
const int MAXN = 1e3 + 10;
int n, m;
int f[MAXN];
bool vis[MAXN];
int findset(int x) { return x == f[x] ? x : f[x] = findset(f[x]); }

void init() {
    for (int i = 1; i <= n; i++) f[i] = i;
    memset(vis, false, sizeof(vis));
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        init();
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            int x = findset(a);
            int y = findset(b);
            if (x != y) f[x] = y;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[findset(i)]) {
                vis[findset(i)] = 1;
                ans++;
            }
        }
        cout << ans << endl;
    }
    // system("pause");
    return 0;
}