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
int dp[MAXN];
int v[MAXN], w[MAXN], s[MAXN];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i] >> s[i];
    }
    for (int i = 1; i <= n; i++)
        for (int k = 1; k <= s[i]; k++)
            for (int j = m; j >= v[i]; j--) {
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            }
    cout << dp[m] << endl;
    // system("pause");
    return 0;
}