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
    int length;
    string tmp, all;
    all = "";

    while (cin >> tmp) {
        all += tmp;
        length = tmp.length();
    }
    cout << length << " ";
    char currentFlag = '0';
    int tmpSum = 0;
    for (char i : all) {
        if (i == currentFlag) {
            tmpSum += 1;
        } else {
            printf("%d ", tmpSum);
            tmpSum = 1;
            if (currentFlag == '0') {
                currentFlag = '1';
            } else {
                currentFlag = '0';
            }
        }
    }
    printf("%d",tmpSum);
    // system("pause");
    return 0;
}