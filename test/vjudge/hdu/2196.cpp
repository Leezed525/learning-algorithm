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
const int MAXN = 10100;
struct node {
    int id;
    int w;
};
vector<node> tree[MAXN];
int n;
int dp[MAXN][3];
void init() {
    for (int i = 1; i <= n; i++) tree[i].clear();
    memset(dp, 0, sizeof(dp));
}

void dfs1(int fa) {
    int one = 0, two = 0;
    for (int i = 0; i < tree[fa].size(); i++) {
        node child = tree[fa][i];
        dfs1(child.id);
        int cost = dp[child.id][0] + child.w;
        if (cost >= one)
            two = one, one = cost;
        else if (cost > two)
            two = cost;
    }
    dp[fa][0] = one;
    dp[fa][1] = two;
}

void dfs2(int fa) {
    for (int i = 0; i < tree[fa].size(); i++) {
        node child = tree[fa][i];
        if (child.w + dp[child.id][0] == dp[fa][0])
            dp[child.id][2] = max(dp[fa][1], dp[fa][2]) + child.w;
        else
            dp[child.id][2] = max(dp[fa][0], dp[fa][2]) + child.w;
        dfs2(child.id);
    }
}

int main() {
    while (cin >> n) {
        init();
        for (int i = 2; i <= n; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            node tmp = {i, b};
            tree[a].push_back(tmp);
        }
        dfs1(1);
        dp[1][2] = 0;
        dfs2(1);
        for (int i = 1; i <= n; i++) printf("%d\n", max(dp[i][0], dp[i][2]));
    }
    // system("pause");
    return 0;
}