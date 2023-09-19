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
const int MAXN = 1e5 + 10;

int f[MAXN * 2];
int vis[MAXN];
int n, m;

int findset(int x) { return x == f[x] ? x : f[x] = findset(f[x]); }
void init() {
    for (int i = 1; i <= 2 * n; i++) f[i] = i;
    memset(vis, false, sizeof(vis));
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        init();
        for (int i = 1; i <= m; i++) {
            getchar();
            char ch;
            int a, b;
            ch = getchar();
            scanf("%d%d", &a, &b);
            if (ch == 'A') {
                if (findset(a) == findset(b))
                    cout << "In the same gang." << endl;
                else if (findset(a) == findset(b + n))
                    cout << "In different gangs." << endl;
                else
                    cout << "Not sure yet." << endl;
            } else {
                int x = findset(a + n);
                int y = findset(b);
                f[x] = y;
                x = findset(a);
                y = findset(b + n);
                f[x] = y;
            }
        }
    }
    // system("pause");
    return 0;
}