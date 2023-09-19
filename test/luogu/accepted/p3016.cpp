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
int n, m;
const int MAXN = 1e5 + 10;
vector<int> g[MAXN];
int a[MAXN];
void dfs(int u, int d) {
    if (a[u]) return;
    a[u] = d;
    for (int i = 0; i < g[u].size(); i++) dfs(g[u][i], d);
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[b].push_back(a);
    }
    for (int i = n; i >= 1; i--) dfs(i, i);
    for (int i = 1; i <= n; i++) printf("%d%c", a[i], i == n ? '\n' : ' ');
    // system("pause");
    return 0;
}