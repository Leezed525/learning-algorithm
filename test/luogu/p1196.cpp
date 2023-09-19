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
const int MAXN = 3e4 + 10;
int f[MAXN];
int d[MAXN];
int s[MAXN];

int getf(int x) {
    if (x == f[x]) return x;
    int tmp = f[x];
    f[x] = getf(f[x]);
    d[x] += d[tmp];
    return f[x];
}

void merge(int a, int b) {
    int x = getf(a);
    int y = getf(b);
    f[x] = y;
    d[x] += s[y];
    s[y] += s[x];
}

void init() {
    for (int i = 1; i < MAXN; i++) {
        f[i] = i;
        d[i] = 0;
        s[i] = 1;
    }
}

int main() {
    // system("pause");
    int T;
    cin >> T;
    init();
    while (T--) {
        char ch;
        int a, b;
        scanf(" %c%d%d", &ch, &a, &b);
        if (ch == 'M') {
            merge(a, b);
        } else {
            int x = getf(a);
            int y = getf(b);
            if (x != y) {
                printf("-1\n");
            } else {
                printf("%d\n", abs(d[a] - d[b]) - 1);
            }
        }
    }
    return 0;
}