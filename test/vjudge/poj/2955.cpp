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
int dp[MAXN][MAXN];
string s;

int main() {
    while (cin >> s && s != "end") {
        memset(dp, 0, sizeof(dp));
        int n = s.length();
        s = 'X' + s;
        for (int len = 1; len < n; len++)
            for (int i = 1; i + len <= n; i++) {
                int j = i + len;
                if ((s[i] == '(' && s[j] == ')') || (s[i] == '[' && s[j] == ']')) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                for (int k = i; k < j; k++) dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                printf("%d ", dp[i][j]);
            }
            printf("\n");
        }
        cout << dp[1][n] << endl;
    }
    // system("pause");
    return 0;
}