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
#define ms(x, n) memset(x, n, sizeof(x));
using namespace std;
//*(int(*)[10])arr_name
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
inline int lowbit(int x) { return x & -x; }

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int a[n + 1];
        int ans[n + 1];
        queue<int> q;
        bool flag[n + 1 + m];
        for (int i = 0; i <= 1 + n + m; i++) {
            flag[i] = false;
        }
        for (int i = n; i >= 1; i -= 1) {
            a[i] = i;
            ans[i] = -1;
            q.push(i);
        }
        int round = 1;

        while (round <= m) {
            int x;
            cin >> x;
            if (q.empty()) {
                round += 1;
                continue;
            }
            if (!flag[x]) {
                flag[x] = true;
                int num = q.front();
                ans[num] = round;
                q.pop();
            }
            round += 1;
        }
        for (int i = 1; i <= n; i += 1) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    // system("pause");
    return 0;
}