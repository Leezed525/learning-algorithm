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
const int MAXN = 255;
int a[MAXN];
int dp[MAXN][MAXN];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int len = 1; len < n; len++)
        for (int i = 1; i + len <= n; i++) {
            int j = i + len;
            
            for(int k = )
        }
    // system("pause");
    return 0;
}