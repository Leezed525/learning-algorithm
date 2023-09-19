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
inline int lowbit(int x) { return x & -x; }

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int count[a * b * c + 1] = {0};
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= c; k++) {
                count[i + j + k]++;
            }
        }
    }
    int maxn = 0;
    int ans = 0;
    for (int i = 1; i < a * b * c + 1; i++) {
        if (count[i] > maxn) {
            maxn = count[i];
            ans = i;
        }
        
    }
    cout << ans << endl;

    // system("pause");
    return 0;
}