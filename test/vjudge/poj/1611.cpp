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
const int MAXN = 3e4 + 10;
int f[MAXN];
int n, m;

void init() {
    for (int i = 0; i < n; i++) f[i] = i;
}

int findset(int x) { return x == f[x] ? x : f[x] = findset(f[x]); }

int main() {
    while (cin >> n >> m && n) {
        init();
        for (int i = 0; i < m; i++) {
            int num, a;
            scanf("%d%d", &num, &a);
            num--;
            while (num--) {
                int b;
                scanf("%d", &b);
                int x = findset(a);
                int y = findset(b);
                if (x != y) {
                    f[x] = y;
                }
            }
        }
        int tmp = findset(0), ans = 0;
        for (int i = 0; i < n; i++) {
            if (findset(i) == tmp) ans++;
        }
        cout << ans << endl;
    }
    // system("pause");
    return 0;
}