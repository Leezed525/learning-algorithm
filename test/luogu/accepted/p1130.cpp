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
const int MAXN = 2e3 + 5;
int dp[MAXN][MAXN];
int a[MAXN][MAXN];
int n,m;

int main()
{
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            dp[i][j] = min(dp[i - 1][j],j == 1?dp[i - 1][m]:dp[i - 1][j - 1]) + a[j][i];
        }
    }
    int ans = INF;
    for(int i = 1;i <= m;i++){
        ans = min(ans,dp[n][i]);
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}