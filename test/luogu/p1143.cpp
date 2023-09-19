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
int base, k;
string s;
int ans = 0;

int getnum(char x) {
    if (x >= 'A' && x <= 'F')
        return x - 'A' + 10;
    else
        return x - '0';
}

void turn(int x) {
    if (x != 0) {
        turn(x / k);
        printf("%c", x % k >= 10 ? x % k - 10 + 'A' : x % k + '0');
    }
}

int main() {
    cin >> base;
    cin >> s;
    cin >> k;
    int tmp = 1;
    for (int i = s.length() - 1; i >= 0; i--) {
        ans += getnum(s[i]) * tmp;
        tmp *= base;
    }
    // cout << ans << endl;
    if (ans == 0)
        printf("0\n");
    else
        turn(ans);
    // system("pause");
    return 0;
}