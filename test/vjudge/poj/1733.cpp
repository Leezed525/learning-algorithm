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
#define lowbit(x) x & -x;
using namespace std;
//*(int(*)[10])arr_name
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);

const int MAXN = 1e4 + 10;
int f[MAXN], d[MAXN], L, n, len;
struct node {
    int a, b, p;
} q[MAXN];
int book[MAXN];
int getf(int x) {
    if (x == f[x]) return x;
    int tmp = f[x];
    f[x] = getf(f[x]);
    d[x] ^= d[tmp];
    return f[x];
}

void init() {
    for (int i = 1; i <= len; i++) {
        f[i] = i;
        d[i] = 0;
    }
}

int getnum(int x) { return lower_bound(book + 1, book + 1 + len, x) - book; }

void read() {
    int num = 0;
    for (int i = 1; i <= n; i++) {
        char ch[5];
        scanf("%d%d%s", &q[i].a, &q[i].b, ch);
        q[i].p = ch[0] == 'o' ? 1 : 0;
        book[++num] = q[i].a - 1;
        book[++num] = q[i].b;
    }
    sort(book + 1, book + num + 1);
    len = unique(book + 1, book + 1 + num) - book - 1;
}

int main() {
    cin >> L >> n;
    read();
    init();
    for (int i = 1; i <= n; i++) {
        int a = getnum(q[i].a - 1);
        int b = getnum(q[i].b);
        int x = getf(a);
        int y = getf(b);
        if (x == y) {
            if (d[a] ^ d[b] != q[i].p) {
                cout << i - 1 << endl;
                return 0;
            }
        } else {
            f[x] = y;
            d[x] = d[a] ^ d[b] ^ q[i].p;
        }
    }
    cout << n << endl;
    // system("pause");
    return 0;
}