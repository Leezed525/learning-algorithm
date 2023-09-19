#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#include<sstream>
using namespace std;
//*(int(*)[10])arr_name
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MAXN = 55;
int a[MAXN][MAXN],dp[MAXN * 2][MAXN][MAXN];
int m,n;
int main()
{
    cin >> m >> n;
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    dp[2][1][1] = 0;
    for(int k = 3;k <= n + m - 1;k++){
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                if(k - i < 1 || k - j < 0)
                    continue;
                dp[k][i][j] = max(max(dp[k - 1][i][j],dp[k - 1][i - 1][j - 1]),max(dp[k - 1][i - 1][j],dp[k - 1][i][j-1]));
                dp[k][i][j] += a[k-i][i] + a[k - j][j];
            }
        }
    }
    cout << dp[m + n - 1][n - 1][n] << endl;
    //system("pause");
    return 0;
}