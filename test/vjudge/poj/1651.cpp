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
int a[MAXN];
int dp[MAXN][MAXN];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int len = 1; len < n; len++)
        for (int i = 2; i + len <= n; i++) {
            int j = i + len;
            dp[i][j] = INF;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] +
                                             a[i - 1] * a[k] * a[j]);
            }
        }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    cout << dp[2][n] << endl;
    // system("pause");
    return 0;
}