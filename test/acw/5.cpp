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
const int MAXN = 2e3 + 10;
int v[MAXN], w[MAXN], dp[MAXN], s[MAXN];
int a[25000], b[25000];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i] >> s[i];
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < s[i]; j <<= 1) {
            a[++cnt] = j * v[i];
            b[cnt] = j * w[i];
            s[i] -= j;
        }
        if (s[i]) {
            a[++cnt] = s[i] * v[i];
            b[cnt] = s[i] * w[i];
        }
    }
    for (int i = 1; i <= cnt; i++) {
        for (int j = m; j >= a[i]; j--) {
            dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
        }
    }
    cout << dp[m] << endl;
    // system("pause");
    return 0;
}