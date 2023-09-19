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
const int MAXN = 1e3 + 10;
int a[MAXN][MAXN];
int mp[MAXN][MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        a[x1][y1]++;
        a[x1][y2 + 1]--;
        a[x2 + 1][y1]--;
        a[x2 + 1][y2 + 1]++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d%c", a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1], j == n ? '\n' : ' ');
        }
    }
    // system("pause");
    return 0;
}