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
    double a, b, c;
    cin >> a >> b >> c;
    double p = 0.5 * (a + b + c);
    double tmp = p * (p - a) * (p - b) * (p - c);
    printf("%.1lf\n", sqrt(tmp));
    // system("pause");
    return 0;
}