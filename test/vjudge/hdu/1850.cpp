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

const int MAXN = 1e6 + 10;
int a[MAXN];
int main() {
    int n;
    while (cin >> n && n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            ans ^= a[i];
        }
        if (!ans)
            cout << 0 << endl;
        else {
            int sum = 0;
            for (int i = 1; i <= n; i++) {
                if ((ans ^ a[i]) <= a[i]) {
                    sum++;
                }
            }
            cout << sum << endl;
        }
    }

    // system("pause");
    return 0;
}