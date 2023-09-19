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
int dis[MAXN];
int n;
vector<int> g[MAXN];
map<string, int> mp;

bool cmp() { return true; }

int bfs(int start) {
    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    dis[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < g[u].size(); i++) {
            int t = g[u][i];
            if (dis[u] + 1 < dis[t]) {
                dis[t] = dis[u] + 1;
                q.push(t);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, dis[i]);
    return res;
}

int main() {
    while (cin >> n && n) {
        for (int i = 1; i <= n; i++)
            g[i].clear();
        mp.clear();
        for (int i = 1; i <= n; i++) {
            string name;
            cin >> name;
            mp[name] = i;
        }
        int m;
        cin >> m;
        for (int i = 1; i <= m; i++) {
            string name1, name2;
            cin >> name1 >> name2;
            g[mp[name1]].push_back(mp[name2]);
            g[mp[name2]].push_back(mp[name1]);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, bfs(i));
        }
        if (ans == INF)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    // system("pause");
    return 0;
}