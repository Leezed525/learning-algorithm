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
struct node {
    int bugs, brains;
} room[MAXN];
int dp[MAXN][MAXN];
int vis[MAXN];
int n, m;
vector<int> mp[MAXN];

void init() {
    memset(dp, 0, sizeof(dp));
    memset(vis,0,sizeof(vis));
    for (int i = 1; i <= n; i++) mp[i].clear();
}

void dfs(int fa) {
    vis[fa] = 1;
    int tmp = (room[fa].bugs + 19) / 20;
    for (int i = m; i >= tmp; i--) dp[fa][i] = room[fa].brains;
    for (int i = 0; i < mp[fa].size(); i++) {
        int son = mp[fa][i];
        if(vis[son])
            continue;
        dfs(son);
        for (int j = m; j >= tmp; j--)
            for (int k = 1; k <= j - tmp; k++) dp[fa][j] = max(dp[fa][j], dp[fa][j - k] + dp[son][k]);
    }
}

int main() {
    while (cin >> n >> m && n != -1 && m != -1) {
        init();
        for (int i = 1; i <= n; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            room[i] = {a, b};
        }
        for (int i = 2; i <= n; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            mp[a].push_back(b);
            mp[b].push_back(a);
        }
        dfs(1);
        if(m == 0)
            cout << 0 << endl;
        else
            cout << dp[1][m] << endl;
    }
    // system("pause");
    return 0;
}
/*
5 10
50 10
40 10
40 20
65 30
70 30
1 2
1 3
2 4
2 5
1 0
20 7
-1 -1
*/