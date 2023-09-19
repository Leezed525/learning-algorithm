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
int a[20];
double ans[MAXN];

bool cmp(double a, double b) { return a > b; }
int main() {
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++) {
        int minn = INF;
        int maxn = 0;
        int sum = 0;
        for (int j = 1; j <= k; j++) {
            int tmp;
            scanf("%d", &tmp);
            maxn = max(tmp, maxn);
            minn = min(tmp, minn);
            sum += tmp;
        }
        ans[i] = (sum - minn - maxn) * 1.0 / (k - 2);
    }
    sort(ans + 1, ans + 1 + n, cmp);
    for (int i = m; i >= 1; i--) {
        printf("%.3lf%c", ans[i], i == 1 ? '\n' : ' ');
    }

    // system("pause");
    return 0;
}