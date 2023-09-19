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
const int MAXN = 2e5 + 10;
int f[MAXN];
int sum[MAXN];
int n, m;
int findset(int x) {
    if (x != f[x]) {
        int t = f[x];
        f[x] = findset(f[x]);
        sum[x] = sum[x] + sum[t];
    }
    return f[x];
}

void init() {
    for (int i = 0; i <= n; i++) {
        f[i] = i;
        sum[i] = 0;
    }
}

int main() {
    while (cin >> n >> m) {
        init();
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            a--;
            int roota = findset(a);
            int rootb = findset(b);
            if (roota != rootb) {
                f[roota] = rootb;
                sum[roota] = sum[b] + c - sum[a];
            } else {
                if (abs(sum[a] - sum[b]) != c) ans++;
            }
        }
        cout << ans << endl;
    }
    // system("pause");
    return 0;
}