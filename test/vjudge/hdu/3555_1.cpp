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

const int MAXN = 21;
LL dp[MAXN][2];
int dig[MAXN];

LL dfs(int pos, bool is4, bool limit) {
    if (pos == 0) return 1;
    if (!limit && dp[pos][is4] != -1) return dp[pos][is4];
    LL res = 0;
    int up = limit ? dig[pos] : 9;
    for (int i = 0; i <= up; i++) {
        if (is4 && i == 9) continue;
        res += dfs(pos - 1, i == 4, limit && i == dig[pos]);
    }
    if (!limit) dp[pos][is4] = res;
    return res;
}

LL solve(LL x) {
    memset(dp, -1, sizeof dp);
    int len = 0;
    while (x) {
        dig[++len] = x % 10;
        x /= 10;
    }
    dig[len + 1] = 0;
    return dfs(len, 0, 1);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        LL n;
        cin >> n;
        cout << n + 1 - solve(n) << endl;
    }
    // system("pause");
    return 0;
}