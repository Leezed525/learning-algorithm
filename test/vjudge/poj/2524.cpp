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
int n, m;
const int MAXN = 5e4 + 10;
int f[MAXN], vis[MAXN];

int findset(int x) { return x == f[x] ? x : f[x] = findset(f[x]); }

void init() {
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    memset(vis, false, sizeof(vis));
}

int main() {
    int cas = 1;
    while (cin >> n >> m && n) {
        init();
        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            int x = findset(a);
            int y = findset(b);
            if (x != y) f[x] = y;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[findset(i)]) {
                ans++;
                vis[findset(i)] = 1;
            }
        }
        printf("Case %d: %d\n", cas++, ans);
    }
    // system("pause");
    return 0;
}