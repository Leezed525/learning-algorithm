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
const int MAXN = 1e3 + 10;
const int MOD = 10007;
int dp[MAXN][MAXN];

int main() {
    int T, cas = 1;
    cin >> T;
    while (T--) {
        memset(dp, 0, sizeof(dp));
        string s;
        cin >> s;
        int n = s.length();
        s = ' ' + s;
        for (int i = 1; i <= n; i++) dp[i][i] = 1;
        for (int len = 1; len < n; len++)
            for (int i = 1; i + len <= n; i++) {
                int j = i + len;
                dp[i][j] = (dp[i][j] + dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] + MOD) % MOD;
                if (s[i] == s[j]) dp[i][j] = (dp[i][j] + dp[i + 1][j - 1] + 1) % MOD;
            }
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         printf("%d ", dp[i][j]);
        //     }
        //     printf("\n");
        // }
        printf("Case %d: %d\n", cas++, dp[1][n]);
    }
    // system("pause");
    return 0;
}