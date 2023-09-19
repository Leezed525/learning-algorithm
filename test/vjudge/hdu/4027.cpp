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
const int MAXN = 1e5 + 10;
LL sum[MAXN << 2];
int n;

inline int lc(int p) { return p << 1; }
inline int rc(int p) { return p << 1 | 1; }
inline void pushup(int p) { sum[p] = sum[lc(p)] + sum[rc(p)]; }

void buildtree(int l, int r, int p) {
    if (l == r) {
        scanf("%lld", &sum[p]);
        return;
    }
    int mid = l + r >> 1;
    buildtree(l, mid, lc(p));
    buildtree(mid + 1, r, rc(p));
    pushup(p);
    return;
}

void update(int l, int r, int ql, int qr, int p) {
    if (l == r) {
        sum[p] = sqrt(sum[p]);
        return;
    }
    if (ql <= l && r <= qr && sum[p] == r - l + 1) return;
    int mid = l + r >> 1;
    if (ql <= mid) update(l, mid, ql, qr, lc(p));
    if (qr > mid) update(mid + 1, r, ql, qr, rc(p));
    pushup(p);
}

LL query(int l, int r, int ql, int qr, int p) {
    if (ql <= l && r <= qr) {
        return sum[p];
    }
    LL res = 0;
    int mid = l + r >> 1;
    if (ql <= mid) res += query(l, mid, ql, qr, lc(p));
    if (qr > mid) res += query(mid + 1, r, ql, qr, rc(p));
    return res;
}

int main() {
    int cas = 0;
    while (cin >> n) {
        buildtree(1, n, 1);
        int m;
        cin >> m;
        printf("Case #%d:\n", ++cas);
        for (int i = 1; i <= m; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            int bb = min(b, c), cc = max(b, c);
            if (a)
                cout << query(1, n, bb, cc, 1) << endl;
            else
                update(1, n, bb, cc, 1);
        }
        cout << endl;
    }
    // system("pause");
    return 0;
}