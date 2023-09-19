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
const int MAXN = 5e4 + 10;
const int mod = 80112002;
vector<int> g[MAXN];
int in[MAXN];
int num[MAXN];
int ans = 0;
int n, m;

void tuopu() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) q.push(i), num[i] = 1;
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (g[u].size() == 0) {
            ans = (ans + num[u]) % mod;
        }
        for (int i = 0; i < g[u].size(); i++) {
            int t = g[u][i];
            in[t]--;
            if (in[t] == 0) q.push(t);
            num[t] = (num[u] + num[t]) % mod;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        in[b]++;
        g[a].push_back(b);
    }
    tuopu();
    cout << ans << endl;
    // system("pause");
    return 0;
}