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
string a, b;
int dp[MAXN][MAXN];
int ans[MAXN];
int main() {
    while (cin >> a >> b) {
        memset(dp, 0, sizeof(dp));
        int n = a.length();
        a = ' ' + a;
        b = ' ' + b;
        for (int i = 1; i <= n; i++) {
            dp[i][i] = 1;
        }
        for (int len = 1; len < n; len++)
            for (int i = 1; i + len <= n; i++) {
                int j = i + len;
                dp[i][j] = dp[i][j - 1] + 1;
                for (int k = i; k < j; k++) {
                    if (b[k] == b[j]) dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k][j - 1]);
                }
            }
        for (int i = 1; i <= n; i++) ans[i] = dp[1][i];
        // for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
        for (int i = 1; i <= n; i++) {
            if (a[i] == b[i])
                ans[i] = ans[i - 1];
            else {
                for (int j = 1; j <= i; j++) {
                    ans[i] = min(ans[i], ans[j] + dp[j + 1][i]);
                }
            }
        }
        cout << ans[n] << endl;
    }
    // system("pause");
    return 0;
}