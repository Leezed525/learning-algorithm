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
const int MAXN = 1e2 + 10;
int a[MAXN];
int sum[MAXN];
int dp[MAXN][MAXN];

int main() {
    int T, cas = 1;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            sum[i] = sum[i - 1] + a[i];
        }
        for (int len = 1; len < n; len++)
            for (int i = 1; i + len <= n; i++) {
                int j = i + len;
                dp[i][j] = INF;
                for (int k = 1; k <= len + 1; k++) {
                    dp[i][j] =
                        min(dp[i][j], dp[i + 1][i + k - 1] + dp[i + k][j] +
                                          k * (sum[j] - sum[i + k - 1]) +
                                          a[i] * (k - 1));
                }
            }
        printf("Case #%d: %d\n", cas++, dp[1][n]);
    }
    // system("pause");
    return 0;
}