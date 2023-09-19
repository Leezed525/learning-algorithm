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
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int mx, my, n, m;
LL dp[25];

bool check(int x, int y) {
    if (x == mx && y == my) {
        return false;
    }
    for (int i = 0; i < 8; i++) {
        int tx = mx + dx[i];
        int ty = my + dy[i];
        if (tx == x && ty == y) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m >> mx >> my;
    n++;
    m++;
    mx++;
    my++;
    dp[1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (check(i, j)) {
                dp[j] += dp[j - 1];
            } else {
                dp[j] = 0;
            }
        }
    }
    cout << dp[m] << endl;
    // system("pause");
    return 0;
}