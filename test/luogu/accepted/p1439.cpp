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
int a[MAXN], t[MAXN];
map<int, int> mp;
int main() {
    int n;
    cin >> n;
    memset(t, 0x3f, sizeof(t));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        mp[a[i]] = i;
    }
    int len = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        *lower_bound(t + 1, t + 1 + n, mp[x]) = mp[x];
    }
    cout << lower_bound(t + 1, t + 1 + n, t[0]) - t - 1 << endl;

    // system("pause");
    return 0;
}