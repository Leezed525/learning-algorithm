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
const int MAXN = 2550;
int l[MAXN][MAXN],on[MAXN][MAXN],a[MAXN][MAXN],dp[MAXN][MAXN],r[MAXN][MAXN];
int n,m;
int main()
{
    cin >> n >> m;
    int ans = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            scanf("%d",&a[i][j]);
            if(!a[i][j]){
                l[i][j] = l[i][j - 1] + 1;
                on[i][j] = on[i - 1][j] + 1;
            }
            else{
                dp[i][j] = min(dp[i - 1][j - 1],min(l[i][j - 1],on[i - 1][j])) + 1;
                ans = max(ans,dp[i][j]);
            }
        }
    }
    memset(dp,0,sizeof(dp));
    for(int i = 1;i <= n;i++){
        for(int j = m;j >= 1;j--){
            if(!a[i][j]){
                r[i][j] = r[i][j + 1] + 1;
            }
            else{
                dp[i][j] = min(dp[i - 1][j + 1],min(r[i][j + 1],on[i - 1][j])) + 1;
                ans = max(ans,dp[i][j]);
            }
        }
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}