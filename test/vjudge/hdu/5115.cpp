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
const int MAXN = 220;
int a[MAXN];
int b[MAXN];
int dp[MAXN][MAXN];

int main() {
    int T, cas = 1;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
        for (int i = 1; i <= n; i++) dp[i][i] = a[i] + b[i - 1] + b[i + 1];
        for (int len = 1; len < n; len++)
            for (int i = 1; i + len <= n; i++) {
                int j = i + len;
                dp[i][j] = INF;
                for (int k = i; k <= j; k++) dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + b[i - 1] + b[j + 1] + a[k]);
            }
        printf("Case #%d: %d\n", cas++, dp[1][n]);
    }
    // system("pause");
    return 0;
}