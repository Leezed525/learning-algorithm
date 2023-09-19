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
int a[MAXN << 1];
int dp[MAXN << 1][MAXN << 1];
int sum[MAXN << 1];
int s[MAXN << 1][MAXN << 1];
int n;
int main() {
    while (cin >> n) {
        memset(s, 0, sizeof(s));
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            a[i + n] = a[i];
            sum[i] = sum[i - 1] + a[i];
            s[i][i] = i;
        }
        for (int i = n + 1; i <= 2 * n; i++)
            sum[i] = sum[i - 1] + a[i], s[i][i] = i;
        for (int len = 1; len < n; len++)
            for (int i = 1, j; (j = i + len) <= 2 * n; i++) {
                dp[i][j] = INF;
                for (int k = s[i][j - 1]; k <= s[i + 1][j]; k++) {
                    if (dp[i][j] >
                        dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]) {
                        dp[i][j] =
                            dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1];
                        s[i][j] = k;
                    }
                }
            }
        int minn = INF;
        for (int i = 1; i <= n; i++)
            minn = min(minn, dp[i][i + n - 1]);
        // for (int i = 1; i <= 2 * n; i++)
        //     for (int j = 1; j <= 2 * n; j++)
        //         printf("%d%c", dp[i][j], j == 2 * n ? '\n' : ' ');
        cout << minn << endl;
    }
    // system("pause");
    return 0;
}