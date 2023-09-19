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
int dp[10][10];
int tmp[10];
void init() {
    dp[0][0] = 1;
    for (int i = 1; i < 10; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 10; k++) {
                if (j == 4 || j == 6 && k == 2) continue;
                dp[i][j] += dp[i - 1][k];
            }
}

int solve(int x)
{
    int len = 0;
    while(x > 0){
        tmp[++len] = x % 10;
        x /= 10;
    }
    tmp[len+1] = 0;
    int res = 0;
    for(int i = len;i > 0;i--){
        for(int j = 0;j < tmp[i];j++){
            if(tmp[i + 1] == 6 && j == 2)  continue;
            res += dp[i][j];
        }
        if(tmp[i] == 4 || tmp[i + 1] == 6 && tmp[i] == 2)
            break;
    }
    return res;
}

int main() {
    int l,r;
    init();
    while(cin >> l >> r){
        if(l == 0 && r == 0)
            return 0;
        cout << solve(r + 1) - solve(l) << endl;
    }
    // system("pause");
    return 0;
}