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
int n, m;
const int MAXN = 1e3 + 10;
int f[MAXN];
int findset(int x) { return f[x] == x ? x : f[x] = findset(f[x]); }

void unionset(int a, int b) {
    int x = findset(a);
    int y = findset(b);
    if (x != y) f[x] = y;
    return;
}

void init() {
    for (int i = 1; i <= n; i++) f[i] = i;
}

int main() {
    while (cin >> n && n) {
        cin >> m;
        init();
        for (int i = 1; i <= m; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            unionset(a, b);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (findset(i) == i) ans++;
        }
        printf("%d\n", ans - 1);
    }
    // system("pause");
    return 0;
}