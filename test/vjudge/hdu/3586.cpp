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
const int INF = 1100000;
const double PI = acos(-1);
const int MAXN = 1e3 + 10;
struct node {
    int t, w;
};
vector<node> g[MAXN];
int dp[MAXN], vis[MAXN];
int n, m;

void dfs(int fa, int num) {
    vis[fa] = 1;
    for (int i = 0; i < g[fa].size(); i++) {
        int child = g[fa][i].t;
        int w = g[fa][i].w;
        if (vis[child] == 1) continue;  //防止死循环
        dfs(child, num);
        if (w > num)  //如果说当前边大于我们二分出来的最大边，就不选
            dp[fa] += dp[child];
        else
            dp[fa] += min(dp[child], w);  //否则就选取孩子节点断开与叶子节点的联系和边权的最小值
    }
}

void init() {  //初始化代码
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 1 && i != 1)  //如果该点度为1且不为根节点，则为叶子节点，初始化为INF
            dp[i] = INF;
        else
            dp[i] = 0;
    }
}

bool judge(int x) {
    init();                       //先初始化
    dfs(1, x);                    //树形dp判断
    if (dp[1] > m) return false;  //如果总权值大于m返回false
    return true;
}

int main() {
    while (cin >> n >> m && n && m) {
        for (int i = 0; i <= n; i++) g[i].clear();
        int r = 0;
        for (int i = 1; i < n; i++) {
            int u, t, w;
            scanf("%d%d%d", &u, &t, &w);
            r = max(r, w);
            g[u].push_back(node{t, w});
            g[t].push_back(node{u, w});
        }
        int l = 1, ans = -1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (judge(mid)) {
                r = mid - 1;
                ans = mid;
            } else
                l = mid + 1;
        }
        cout << ans << endl;
    }
    // system("pause");
    return 0;
}