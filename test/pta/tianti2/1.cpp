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

int main() {
    string s;
    cin >> s;
    int fu = 0;
    if (s[0] == '-') fu = 1;
    int ou = 0;
    if ((s[s.length() - 1] - '0') % 2 == 0) ou = 1;
    int ershu = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '2') ershu++;
    }
    double ans = 0;
    if (fu) {
        ans = ershu * 1.0 / (s.length() - 1);
    } else {
        ans = ershu * 1.0 / s.length();
    }
    if (fu) ans = ans * 1.5;
    if (ou) ans = ans * 2;
    printf("%.2lf%%\n", ans * 100);
    // system("pause");
    return 0;
}