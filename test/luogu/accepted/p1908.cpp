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
LL n;
const int MAXN = 5e6 + 5;
LL a[MAXN], b[MAXN], ans = 0;

void merge(LL l, LL mid, LL r)
{
    LL i = l, j = mid + 1, t = 0;
    while (i <= mid && j <= r)
    {
        if (a[i] > a[j])
        {
            b[t++] = a[j++];
            ans += mid - i + 1;
        }
        else
            b[t++] = a[i++];
    }
    while (i <= mid)
        b[t++] = a[i++];
    while (j <= r)
        b[t++] = a[j++];
    for (i = 0; i < t; i++)
        a[l + i] = b[i];
}

void mergesort(LL l, LL r)
{
    if (l == r)
        return;
    LL mid = (l + r) / 2;
    mergesort(l, mid);
    mergesort(mid + 1, r);
    LL i = l, j = mid + 1, t = l;
    while (i <= mid && j <= r)
    {
        if (a[i] > a[j])
        {
            b[t++] = a[j++];
            ans += mid - i + 1;
        }
        else
            b[t++] = a[i++];
    }
    while (i <= mid)
        b[t++] = a[i++];
    while (j <= r)
        b[t++] = a[j++];
    for (i = l; i <= r; i++)
        a[i] = b[i];
}
int main()
{
    //freopen("text.out","w",stdout);
    cin >> n;
    for (LL i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    mergesort(1, n);
    // for(int i = 0;i < n;i++){
    //     printf("%d ",a[i]);
    // }
    printf("%lld\n", ans);
    return 0;
}