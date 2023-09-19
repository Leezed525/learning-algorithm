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

struct student {
    int chinese;
    int math;
    int english;

    student() {}

    student(int a, int b, int c) {
        this->chinese = a;
        this->math = b;
        this->english = c;
    }
    int sum() { return this->chinese + this->english + this->math; }
};

bool verify(student a, student b) {
    if (abs(a.chinese - b.chinese) <= 5 && abs(a.english - b.english) <= 5 && abs(a.math - b.math) <= 5 &&
        abs(a.sum() - b.sum()) <= 10) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    cin >> n;
    student a[n + 1];
    for (int i = 1; i <= n; i += 1) {
        cin >> a[i].chinese >> a[i].math >> a[i].english;
    }
    int ans = 0;
    for (int i = 1; i <= n; i += 1) {
        for (int j = i + 1; j <= n; j += 1) {
            if (verify(a[i], a[j])) {
                ans += 1;
            }
        }
    }
    cout << ans << endl;
    // system("pause");
    return 0;
}