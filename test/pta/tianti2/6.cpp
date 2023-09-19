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
    int n;
    cin >> n;
    int ji = 0, ou = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x & 1)
            ji++;
        else
            ou++;
    }
    cout << ji << " " << ou << endl;
    // system("pause");
    return 0;
}