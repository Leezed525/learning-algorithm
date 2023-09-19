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
int f[MAXN << 1];
int op[MAXN][MAXN];
int n, m, k;

int findset(int x) { return f[x] == x ? x : f[x] = findset(f[x]); }
void init() {
    for (int i = 1; i <= n; i++) f[i] = i;
}

int main() {
    cin >> n >> m >> k;
    init();
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c == 1) {
            int x = findset(a);
            int y = findset(b);
            if (x != y) f[x] = y;
        } else {
            op[a][b] = 1;
            op[b][a] = 1;
        }
    }
    for (int i = 1; i <= k; i++) {
        int a, b;
        cin >> a >> b;
        if (findset(a) == findset(b)) {
            if (op[a][b] == 1)
                cout << "OK but..." << endl;
            else {
                cout << "No problem" << endl;
            }
        } else {
            if (op[a][b] == 1)
                cout << "No way" << endl;
            else {
                cout << "OK" << endl;
            }
        }
    }
    // system("pause");
    return 0;
}
