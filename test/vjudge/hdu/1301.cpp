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
int n;
const int MAXN = 50;
int f[MAXN];
int findset(int x) { return x == f[x] ? f[x] : f[x] = findset(f[x]); }

struct edge {
    int u, v, w;
    edge(int a, int b, int c) {
        u = a;
        v = b;
        w = c;
    }
    bool operator<(const edge &T) const { return w > T.w; }
};
priority_queue<edge> q;

int kurskal() {
    int res = 0;
    while (!q.empty()) {
        edge tmp = q.top();
        q.pop();
        int x = findset(tmp.u);
        int y = findset(tmp.v);
        if (x != y) {
            f[x] = y;
            res += tmp.w;
        }
    }
    return res;
}

void init() {
    for (int i = 1; i <= n; i++) f[i] = i;
    while (!q.empty()) q.pop();
}

int main() {
    while (cin >> n && n) {
        init();
        for (int i = 1; i < n; i++) {
            char ch;
            int u, v, w, m;
            scanf(" %c %d", &ch, &m);
            // cout << ch << " " << m;
            u = ch - 'A' + 1;
            for (int j = 1; j <= m; j++) {
                scanf(" %c %d", &ch, &w);
                v = ch - 'A' + 1;
                q.push(edge(u, v, w));
            }
        }
        cout << kurskal() << endl;
    }
    // system("pause");
    return 0;
}