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

int main() {
    int n;
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        ans ^= x;
    }
    cout << ans << endl;
    // system("pause");
    return 0;
}