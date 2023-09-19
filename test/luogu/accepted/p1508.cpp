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
const int MAXN = 210;
int a[MAXN][MAXN],dp[MAXN][MAXN];
int main()
{
    int m,n;
    cin >> m >> n;
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    // for(int i = 1;i <= m;i++){
    //     a[i][0] = -INF;
    //     a[i][n] = -INF;
    // }
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            dp[i][j] = max(max(dp[i - 1][j],dp[i - 1][j - 1]),dp[i - 1][j + 1]) + a[i][j];
        }
    }
    cout << max(max(dp[m][(n + 1) / 2],dp[m][n / 2]),dp[m][(n+1) / 2 + 1]) << endl;
    //system("pause");
    return 0;
}