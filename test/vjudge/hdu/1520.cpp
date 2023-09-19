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
const int MAXN = 6e3 + 10;
int value[MAXN], fa[MAXN];
int dp[MAXN][2];
vector<int> tree[MAXN];

void dfs(int u) {
    dp[u][0] = 0;
    dp[u][1] = value[u];
    for (int i = 0; i < tree[u].size(); i++) {
        int son = tree[u][i];
        dfs(son);
        dp[u][0] += max(dp[son][1], dp[son][0]);
        dp[u][1] += dp[son][0];
    }
}

int main() {
    int n;
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &value[i]);
            tree[i].clear();
            fa[i] = -1;
        }
        int a, b;
        while (~scanf("%d%d", &a, &b) && (a || b)) {
            fa[a] = b;
            tree[b].push_back(a);
        }
        int t = 1;
        while (fa[t] != -1) t = fa[t];
        dfs(t);
        cout << max(dp[t][0], dp[t][1]) << endl;
    }
    // system("pause");
    return 0;
}