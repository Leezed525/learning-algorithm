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
const int MAXN = 1e4 + 10;
int n;
struct node
{
    int l, r;
    int sum;
} tree[MAXN * 4];
int pre[MAXN], ans[MAXN];
inline int lc(int p)
{
    return p << 1;
}
inline int rc(int p)
{
    return p << 1 | 1;
}

void buildtree(int p, int l, int r)
{
    tree[p].l = l;
    tree[p].r = r;
    if (l == r)
    {
        tree[p].sum = 1;
        return;
    }
    int mid = l + r >> 1;
    buildtree(lc(p), l, mid);
    buildtree(rc(p), mid + 1, r);
    tree[p].sum = tree[lc(p)].sum + tree[rc(p)].sum;
}

int quary(int p, int l, int r, int q)
{
    int mid = l + r >> 1;
    int res;
    if (q == 1 && tree[p].l == tree[p].r)
    {
        tree[p].sum = 0;
        return tree[p].l;
    }
    if (tree[lc(p)].sum >= q)
    {
        res = quary(lc(p), l, mid, q);
    }
    else
    {
        q -= tree[lc(p)].sum;
        res = quary(rc(p), mid + 1, r, q);
    }
    tree[p].sum = tree[lc(p)].sum + tree[rc(p)].sum;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    cout << (1 << (int(log(n) / log(2)) + 1));
    pre[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        cin >> pre[i];
    }
    buildtree(1, 1, n);
    for (int i = n; i >= 1; i--)
    {
        ans[i] = quary(1, 1, n, pre[i] + 1);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }
    //system("pause");
    return 0;
}