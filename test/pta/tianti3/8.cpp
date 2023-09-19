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
    int k;
    char ch;
    cin >> k >> ch;
    getchar();
    string s;
    getline(cin, s);
    int len = s.length();
    if (len > k)
        cout << s.substr(len - k, k) << endl;
    else {
        for (int i = 1; i <= k - len; i++) printf("%c", ch);
        cout << s << endl;
    }
    // system("pause");
    return 0;
}