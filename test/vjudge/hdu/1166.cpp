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
const int MAXN = 5e4 + 10;
int n, num[MAXN];
struct node
{
    int l, r;
    int sum;
} tree[MAXN * 4];

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
        tree[p].sum = num[l];
        return;
    }
    int mid = l + r >> 1;
    buildtree(lc(p), l, mid);
    buildtree(rc(p), mid + 1, r);
    push_up(p);
}

void update(int pos, int l, int r, int p, int k)
{
    if (l == r && l == pos)
    {
        tree[p].sum += k;
        return;
    }
    int mid = l + r >> 1;
    if (pos <= mid)
        update(pos, l, mid, lc(p), k);
    else
        update(pos, mid + 1, r, rc(p), k);
    push_up(p);
}

int quary(int nl, int nr, int l, int r, int p)
{
    if (nl <= l && nr >= r)
        return tree[p].sum;
    int res = 0;
    int mid = l + r >> 1;
    if (nl <= mid)
        res += quary(nl, nr, l, mid, lc(p));
    if (nr > mid)
        res += quary(nl, nr, mid + 1, r, rc(p));
    return res;
}

int main()
{
    int T, cas = 1;
    cin >> T;
    while (T--)
    {
        printf("Case %d:\n", cas++);
        cin >> n;
        for (int i = 1; i <= n; i++)
            scanf("%d", &num[i]);
        buildtree(1, 1, n);
        string way;
        while (cin >> way)
        {
            if (way == "End")
                break;
            if (way == "Query")
            {
                int l, r;
                scanf("%d%d", &l, &r);
                cout << quary(l, r, 1, n, 1) << endl;
            }
            else if (way == "Add")
            {
                int pos, k;
                scanf("%d%d", &pos, &k);
                update(pos, 1, n, 1, k);
            }
            else if (way == "Sub")
            {
                int pos, k;
                scanf("%d%d", &pos, &k);
                update(pos, 1, n, 1, -k);
            }
        }
    }
    //system("pause");
    return 0;
}