#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <bitset>
#include <cstdlib>
#include <cmath>
#include <set>
#include <list>
#include <deque>
#include <map>
#include <queue>
#include <sstream>
using namespace std;
//*(int(*)[10])arr_name
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;
LL as[MAXN];
int n, q;
struct node
{
    int l, r;
    LL tag, sum;
    node()
    {
        tag = 0;
        sum = 0;
    }
} tree[4 * MAXN];
inline int lc(int p)
{
    return p << 1;
}
inline int rc(int p)
{
    return p << 1 | 1;
}

inline void push_up(int p)
{
    tree[p].sum = tree[lc(p)].sum + tree[rc(p)].sum;
}

void buildtree(int p, int l, int r)
{
    tree[p].l = l;
    tree[p].r = r;
    if (l == r)
    {
        tree[p].sum = as[l];
        return;
    }
    int mid = l + r >> 1;
    buildtree(lc(p), l, mid);
    buildtree(rc(p), mid + 1, r);
    push_up(p);
}

inline void F(int p, int l, int r, LL k)
{
    tree[p].sum += LL(r - l + 1) * k;
    tree[p].tag += k;
}

inline void push_down(int p, int l, int r)
{
    int mid = l + r >> 1;
    F(lc(p), l, mid, tree[p].tag);
    F(rc(p), mid + 1, r, tree[p].tag);
    tree[p].tag = 0;
}

void update(int nl, int nr, int l, int r, int p, LL k)
{
    if (nl <= l && nr >= r)
    {
        tree[p].sum += LL(r - l + 1) * k;
        tree[p].tag += k;
        return;
    }
    push_down(p, l, r);
    int mid = l + r >> 1;
    if (nl <= mid)
        update(nl, nr, l, mid, lc(p), k);
    if (nr > mid)
        update(nl, nr, mid + 1, r, rc(p), k);
    push_up(p);
}

LL quary(int nl, int nr, int l, int r, int p)
{
    if (nl <= l && nr >= r)
        return tree[p].sum;
    LL res = 0;
    push_down(p, l, r);
    int mid = l + r >> 1;
    if (nl <= mid)
        res += quary(nl, nr, l, mid, lc(p));
    if (nr > mid)
        res += quary(nl, nr, mid + 1, r, rc(p));
    return res;
}

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> as[i];
    }
    buildtree(1, 1, n);
    for (int i = 0; i < q; i++)
    {
        char s;
        cin >> s;
        if (s == 'C')
        {
            int l, r;
            LL k;
            cin >> l >> r >>k;
            update(l, r, 1, n, 1, k);
        }
        else
        {
            int l,r;
            cin >> l >>r;
            cout << quary(l, r, 1, n, 1) << endl;
        }
    }
    //system("pause");
    return 0;
}