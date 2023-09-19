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
LL base = 131;
int prime = 233317;
LL mod = 212370440130137957LL;
string s;
int n;
const int MAXN = 1e4 + 10;
LL a[MAXN];

LL hashs() {
    LL ans = 0;
    for (int i = 0; i < s.length(); i++) ans = (ans * base + s[i]) % mod + prime;
    return ans;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        a[i] = hashs();
    }
    sort(a + 1, a + 1 + n);
    cout << unique(a + 1, a + 1 + n) - a - 1 << endl;
    // system("pause");
    return 0;
}