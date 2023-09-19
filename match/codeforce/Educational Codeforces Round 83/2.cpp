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
int a[MAXN];

bool cmp(int x, int y) { return x > y; }

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a + 1, a + 1 + n, cmp);
        for (int i = 1; i <= n; i++) {
            printf("%d%c", a[i], i == n ? '\n' : ' ');
        }
    }
    // system("pause");
    return 0;
}