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
int f[MAXN], cnt = 0;
int findset(int x) { return x == f[x] ? x : f[x] = findset(f[x]); }
struct Edge {
    int u, v, w;
} edge[MAXN * MAXN];
int n, counts = 0;

bool cmp(Edge a, Edge b) { return a.w < b.w; }

void krusal()
{
    int res = 0;
    for(int i = 0;i < cnt;i++){
        if(counts == n - 1)
            break;
        int x = findset(edge[i].u);
        int y = findset(edge[i].v);
        if(x != y){
            f[x] = y;
            res += edge[i].w;
        }
    }
    cout << res << endl;
}

int main() {
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            scanf("%d", &x);
            if (i == j) continue;
            edge[cnt].u = i;
            edge[cnt].v = j;
            edge[cnt++].w = x;
        }
    }
    sort(edge, edge + cnt, cmp);
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        int x = findset(a);
        int y = findset(b);
        if (x != y) f[x] = y;
        counts++;
    }
    krusal();
    // system("pause");
    return 0;
}