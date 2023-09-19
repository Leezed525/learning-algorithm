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
const double PI = acos(-1);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        double tmp = (a - 100) * 0.9 * 2;
        if (abs(tmp - b) < tmp * 0.1)
            cout << "You are wan mei!" << endl;
        else {
            if (tmp < b)
                cout << "You are tai pang le!" << endl;

            else
                cout << "You are tai shou le!" << endl;
        }
    }
    // system("pause");
    return 0;
}