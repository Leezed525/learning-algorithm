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
    int n;
    cin >> n;
    stack<int> s;
    s.push(n);
    while (n != 1) {
        if (n % 2 == 1) {
            n = n * 3 + 1;
        } else {
            n = n / 2;
        }
        s.push(n);
    }
    while(!s.empty()){
        printf("%d ",s.top());
        s.pop();
    }
    // system("pause");
    return 0;
}