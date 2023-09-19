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
const int MAXN = 1e6 + 10;
int a[MAXN];
int n, m;

void lower(int k) {
    int l = 1, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        if (a[mid] < k)
            l = mid + 1;
        else
            r = mid;
    }
    if (a[l] == k)
        cout << l << " ";
    else
        cout << -1 << " ";
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        int k;
        scanf("%d", &k);
        lower(k);
    }
    // system("pause");
    return 0;
}