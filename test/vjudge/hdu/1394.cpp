#include<cstdio>

#include<cstring>

#include<algorithm>

#include<iostream>

#include<string>

#include<vector>

#include<stack>

#include<bitset>

#include<cstdlib>

#include<cmath>

#include<set>

#include<list>

#include<deque>

#include<map>

#include<queue>

#include<sstream>

using namespace std;
//*(int(*)[10])arr_name
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MAXN = 5e3 + 10;
int n, a[MAXN];
struct node {
    int l, r, num;
}
tree[MAXN * 4];
inline int lc(int p) {
    return p << 1;
}
inline int rc(int p) {
    return p << 1 | 1;
}
inline void push_up(int p) {
    tree[p].num = tree[lc(p)].num + tree[rc(p)].num;
}
void buildtree(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    if (l == r) {
        tree[p].num = 0;
        return;
    }
    int mid = l + r >> 1;
    buildtree(lc(p), l, mid);
    buildtree(rc(p), mid + 1, r);
    push_up(p);
}

int query(int p, int l, int r) {
    if (l <= tree[p].l && r >= tree[p].r)
        return tree[p].num;
    int res = 0;
    int mid = tree[p].l + tree[p].r >> 1;
    if (l <= mid) res += query(lc(p), l, r);
    if (r > mid) res += query(rc(p), l, r);
    return res;
}

void update(int k, int p) {
    if (tree[p].l == tree[p].r && tree[p].l == k) {
        tree[p].num++;
        return;
    }
    int mid = tree[p].l + tree[p].r >> 1;
    if (k <= mid) update(k, lc(p));
    if (k > mid) update(k, rc(p));
    push_up(p);
}

int main() {
    while (cin >> n) {
        buildtree(1, 0, n - 1);
        int res = 0, minn;
        for (int i = 1; i <= n; i++) {
            scanf("%d", & a[i]);
            res += query(1, a[i] + 1, n - 1);
            update(a[i], 1);
        }
        cout << res << endl;
        minn = res;
        for (int i = 1; i <= n; i++) {
            res += n - a[i] * 2 - 1;
            minn = min(minn, res);
        }
        cout << minn << endl;

    }
    //system("pause");
    return 0;
}
