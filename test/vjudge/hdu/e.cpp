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
const int MAXN = 1e4 + 10;
int dp[MAXN][2];
int main() {
    string s;
    cin >> s;
    dp[0][0] = 0;
    dp[0][1] = 1;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        dp[i + 1][0] = min(dp[i][0] + s[i] - '0', dp[i][1] + 10 - s[i] + '0');
        dp[i + 1][1] = min(dp[i][0] + s[i] - '0' + 1, dp[i][1] + 10 - s[i] + '0' - 1);
    }
    cout << dp[len][0] << endl;

    // system("pause");
    return 0;
}