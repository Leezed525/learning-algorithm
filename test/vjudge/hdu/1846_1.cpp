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
int n, m;
const int MAXN = 1e3 + 10;
int sg[MAXN];
int s[MAXN];

void getsg() {
    ms(sg, 0);
    for (int i = 1; i <= n; i++) {
        ms(s, 0);
        for (int j = 1; j <= m && j <= i; j++) {
            s[sg[i - j]] = 1;
        }
        for (int j = 1; j <= n; j++) {
            if (!s[j]) {
                sg[i] = j;
                break;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        getsg();
        if (sg[n])
            cout << "first" << endl;
        else
            cout << "second" << endl;
    }
    // system("pause");
    return 0;
}