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
const int MAXN = 50;
LL dp[MAXN][10];
void init() {
    dp[0][0] = 1;
    for (int i = 1; i <= 25; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                if (j == 4 && k == 9) continue;
                dp[i][j] += dp[i - 1][k];
            }
        }
    }
}

LL solve(LL x) {
    int dig[20], len = 0;
    while (x > 0) {
        dig[++len] = x % 10;
        x /= 10;
    }
    dig[len + 1] = 0;
    LL res = 0;
    for (int i = len; i >= 1; i--) {
        for (int j = 0; j < dig[i]; j++) {
            if (j == 9 && dig[i + 1] == 4) continue;
            res += dp[i][j];
        }
        if (dig[i] == 9 && dig[i + 1] == 4) break;
    }
    return res;
}

int main() {
    int T;
    init();
    cin >> T;
    while (T--) {
        LL n;
        cin >> n;
        cout << n - solve(n + 1) + 1 << endl;
        // for (int i = 0; i < 10; i++) printf("%d\n", dp[3][i]);
    }
    // system("pause");
    return 0;
}