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
const int MAXN = 205;
int a[MAXN][MAXN];
int dp[MAXN];
int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n - 1;i++){
        for(int j = i + 1;j <= n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    memset(dp,0x3f,sizeof(dp));
    dp[1] = 0;
    for(int i = 2;i <= n;i++){
        for(int j = 1;j < i;j++){
            dp[i] = min(dp[i],dp[j] + a[j][i]);
        }
    }
    cout << dp[n] << endl;
    //system("pause");
    return 0;
}