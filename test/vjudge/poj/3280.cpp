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
const int MAXN = 2050;
int dp[MAXN][MAXN];
int w[26];
int n, len;
string s;
int main() {
    cin >> n >> len;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        getchar();
        char ch;
        int w1,w2;
        scanf("%c %d %d", &ch, &w1, &w2);
        w[ch - 'a'] = min(w1, w2);
    }
    for (int i = len - 1; i >= 0; i--)
        for (int j = i + 1; j < len; j++) {
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1];
            else
                dp[i][j] = min(dp[i + 1][j] + w[s[i] - 'a'],
                               dp[i][j - 1] + w[s[j] - 'a']);
        }
    cout << dp[0][len - 1] << endl;
    // system("pause");
    return 0;
}