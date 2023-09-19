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
const int MAXN = 2e2 + 10;
int dp[MAXN][MAXN];
int pos[MAXN][MAXN];
string s;
string print(int l, int r) {
    if (l > r) return "";
    if (l == r) {
        if (s[l] == '(' || s[r] == ')')
            return "()";
        else
            return "[]";
    } else if (pos[l][r] == -1)
        return s[l] + print(l + 1, r - 1) + s[r];
    else
        return print(l, pos[l][r]) + print(pos[l][r] + 1, r);
}

int main() {
    while (getline(cin, s)) {
        memset(dp, 0, sizeof(dp));
        memset(pos, 0, sizeof(pos));
        int n = s.length();
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int len = 1; len < n; len++)
            for (int i = 0; i + len < n; i++) {
                int j = i + len;
                dp[i][j] = INF;
                if (s[i] == '(' && s[j] == ')' || s[i] == '[' && s[j] == ']')
                    dp[i][j] = dp[i + 1][j - 1], pos[i][j] = -1;
                for (int k = i; k < j; k++)
                    if (dp[i][j] > dp[i][k] + dp[k + 1][j]) {
                        dp[i][j] = dp[i][k] + dp[k + 1][j];
                        pos[i][j] = k;
                    }
            }
        // for(int i = 1;i <= n;i++){
        //     for(int j = 1;j <= n;j++){
        //         printf("%d ",dp[i][j]);
        //     }
        //     printf("\n");
        // }
        // for(int i = 1;i <= n;i++){
        //     for(int j = 1;j <= n;j++){
        //         printf("%d ",pos[i][j]);
        //     }
        //     printf("\n");
        // }
        cout << print(0, n - 1) << endl;
    }
    // system("pause");
    return 0;
}