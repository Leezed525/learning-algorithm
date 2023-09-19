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
const int MAXN = 1e2 + 10;
const int MOD = 1000007;
int a[MAXN];
int f[MAXN][MAXN];
int n, m;
int dfs(int counts, int sum) {
    if (sum == m)
        return 1;
    if (sum > m)
        return 0;
    if (counts == n + 1)
        return 0;
    if (f[counts][sum])
        return f[counts][sum];
    int res = 0;
    for (int i = 0; i <= a[counts]; i++) {
        res = (res + dfs(counts + 1, sum + i) % MOD) % MOD;
    }
    f[counts][sum] = res;
    return res;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cout << dfs(1, 0) << endl;
    // system("pause");
    return 0;
}