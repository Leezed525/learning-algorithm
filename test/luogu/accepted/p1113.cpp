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
const int MAXN = 1e4 + 10;
int ans[MAXN];
int maxans = 0;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u, l, t;
        scanf("%d%d", &u, &l);
        while (scanf("%d", &t) && t) {
            ans[u] = max(ans[u], ans[t]);
        }
        ans[u] += l;
        maxans = max(maxans, ans[u]);
    }
    cout << maxans << endl;
    // system("pause");
    return 0;
}