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
int dp[MAXN * 2][MAXN * 2];
int a[MAXN];
int main() {
    int n;
    while (cin >> n && n) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            a[i + n] = a[i];
            dp[i][i] = dp[i + n][i + n] = 1;
        }

        for (int len = 1; len < n; len++)
            for (int i = 1; i + len <= 2 * n; i++) {
                int j = i + len;
                dp[i][j] = max(dp[i + 1][j],dp[i][j - 1]);
                if(a[i] == a[j])
                    dp[i][j] = max(dp[i][j],dp[i + 1][j - 1] + 2);
            }
        int ans = 0;
        for(int i = 1;i <= n;i++){
            ans = max(ans,dp[i][i + n - 1]);
            ans = max(ans,dp[i][i + n - 2] + 1);
        }
        cout << ans << endl;
    }
    // system("pause");
    return 0;
}