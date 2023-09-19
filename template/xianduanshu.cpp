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
struct node {
    int l, r;
    LL tag, sum;
} tree[4 * MAXN];
LL a[MAXN];
int n, m;

int ls(int p) { return p << 1; }

int rs(int p) { return p << 1 | 1; }

void push_up(int p) { tree[p].sum = tree[ls(p)].sum + tree[rs(p)].sum; }

void build(int p, int l, int r) {
    if (l == r) {
        tree[p].sum = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    push_up(p);
}

void f(int p, int l, int r, LL k) {
    tree[p].sum += k * (r - l + 1);
    tree[p].tag += k;
}

void push_down(int p, int l, int r) {
    int mid = l + r >> 1;
    f(ls(p), l, mid, tree[p].tag);
    f(rs(p), mid + 1, r, tree[p].tag);
    tree[p].tag = 0;
}

void update(int nl, int nr, int l, int r, int p, LL k) {
    if (nl <= l && r <= nr) {
        tree[p].sum += k * (r - l + 1);
        tree[p].tag += k;
        return;
    }
    push_down(p, l, r);
    int mid = l + r >> 1;
    if (nl <= mid) update(nl, nr, l, mid, ls(p), k);
    if (nr > mid) update(nl, nr, mid + 1, r, rs(p), k);
    push_up(p);
}

LL quary(int ql, int qr, int l, int r, int p) {
    LL ans = 0;
    if (ql <= l && qr >= r) return tree[p].sum;
    int mid = l + r >> 1;
    push_down(p, l, r);
    if (ql <= mid) ans += quary(ql, qr, l, mid, ls(p));
    if (qr > mid) ans += quary(ql, qr, mid + 1, r, rs(p));
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    build(1, 1, n);
    for (int i = 0; i < m; i++) {
        int q;
        scanf("%d", &q);
        if (q == 1) {
            int l, r;
            LL k;
            scanf("%d%d%lld", &l, &r, &k);
            update(l, r, 1, n, 1, k);
        } else {
            int l, r;
            scanf("%d%d", &l, &r);
            cout << quary(l, r, 1, n, 1) << endl;
        }
    }
    // system("pause");
    return 0;
}