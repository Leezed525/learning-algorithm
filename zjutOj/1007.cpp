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

// not AC
int main() {
    int n, m;
    cin >> n >> m;
    bool flag[n + 1];
    flag[1] = true;
    int areaCount = 1;
    long sideSum = 0;
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int area, side;
            cin >> area >> side;
            if (!flag[area]) {
                flag[area] = true;
                areaCount += 1;
            }
            sideSum += side;
        } else {
            printf("%d %ld\n", areaCount, sideSum);
        }
    }
    // system("pause");
    return 0;
}