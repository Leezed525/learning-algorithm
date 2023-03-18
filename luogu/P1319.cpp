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
    vector<int> a;
    int tmpSum = 0;
    while (tmpSum < n * n) {
        int x;
        cin >> x;
        tmpSum += x;
        a.push_back(x);
    }
    string ans = "";
    int count = 0;
    bool currentFlag = false;
    for (int i : a) {
        for (int j = 0; j < i; j += 1) {
            count += 1;
            if (currentFlag) {
                ans.push_back('1');
            } else {
                ans.push_back('0');
            }
            if (count == n) {
                ans.push_back('\n');
                count = 0;
            }
        }
        currentFlag = !currentFlag;
    }
    cout << ans << endl;
    // system("pause");
    return 0;
}