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
const int MAXN = 5e2 + 10;
int f[MAXN];
int mp[MAXN][MAXN];
int n, m;
int findset(int x) { return x == f[x] ? x : f[x] = findset(f[x]); }
void merge(int a, int b) {
    int x = findset(a);
    int y = findset(b);
    if (x != y) f[x] = y;
    return;
}
void init() {
    for (int i = 0; i < n; i++) f[i] = i;
}

int quary() {
    int res = 0;
    for (int i = 0; i < n; i++)
        if (f[i] == i) res++;
    return res;
}

int main() {
    cin >> n >> m;
    init();
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        mp[a][b] = mp[b][a] = 1;
        merge(a, b);
    }
    int k;
    cin >> k;
    int pre = quary(), now;
    for (int z = 1; z <= k; z++) {
        init();
        int u;
        scanf("%d", &u);
        for (int i = 0; i < n; i++) mp[u][i] = mp[i][u] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (mp[i][j]) merge(i, j);
        now = quary();
        if (now > pre + 1)
            printf("Red Alert: City %d is lost!\n", u);
        else
            printf("City %d is lost.\n", u);
        pre = now;
    }
    if (k == n) cout << "Game Over." << endl;
    // system("pause");
    return 0;
}