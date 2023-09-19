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
int dig[20];
int dp[20][2];
int dfs(int pos, bool is6, bool limit) {
    if (pos == 0) return 1;
    if (!limit && dp[pos][is6] != -1) return dp[pos][is6];
    int up = limit ? dig[pos] : 9;
    int res = 0;
    for (int i = 0; i <= up; i++) {
        if (is6 && i == 2) continue;
        if (i == 4) continue;
        res += dfs(pos - 1,i == 6,limit && i == dig[pos]);
    }
    if(!limit)
        dp[pos][is6] = res;
    return res;
}

int solve(int x)
{
    int len = 0;
    while(x){
        dig[++len] = x % 10;
        x /= 10;
    }
    dig[len + 1] = 0;
    return dfs(len,0,1);
}

int main() {
    int l,r;
    while(cin >> l >> r && l + r){
        memset(dp,-1,sizeof dp);
        cout << solve(r) - solve(l - 1) <<endl;
    }
    // system("pause");
    return 0;
}