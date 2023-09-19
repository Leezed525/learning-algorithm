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
const int MAXN = 2e2 + 10;
struct node {
    int to, w;
};
int value[MAXN];
vector<node> g[MAXN];
int n, m;
int dp[MAXN][MAXN];

void dfs(int fa) {
    for (int j = 1; j <= m; j++) 
        dp[fa][j] = value[fa];
    for (int i = 0; i < g[fa].size(); i++) {
        int child = g[fa][i].to;
        int w = g[fa][i].w;
        dfs(child);
        for (int j = m; j >= 1; j--) 
            for (int k = 1; k <= j - 1; k++) {
                dp[fa][j] = max(dp[fa][j], dp[fa][j - k] + dp[child][k]);
            }
    }
}

void init() {
    for (int i = 0; i <= n; i++) g[i].clear();
    memset(dp, 0, sizeof dp);
}

int main() {
    while (cin >> n >> m && n && m) {
        m++;
        init();
        for (int i = 1; i <= n; i++) {
            int u, w;
            scanf("%d%d", &u, &w);
            value[i] = w;
            node tmp = {i, w};
            g[u].push_back(tmp);
        }
        dfs(0);
        cout << dp[0][m] <<endl;
    }
    // system("pause");
    return 0;
}