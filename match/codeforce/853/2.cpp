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
    int T;
    cin >> T;
    while (T--) {
        int len;
        cin >> len;
        string s;
        cin >> s;
        s = 'a' + s;
        bool flag[len + 1];
        for (int i = 0; i <= len; i++) {
            flag[i] = false;
        }
        for (int i = 1; i <= len / 2; i += 1) {
            if (s[i] != s[len - i + 1]) {
                flag[i] = true;
            }
        }
        int area = 0;
        for (int i = 1; i <= len / 2; i += 1) {
            if (flag[i] && !flag[i - 1]) {
                area += 1;
            }
        }
        if (area <= 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    // system("pause");
    return 0;
}