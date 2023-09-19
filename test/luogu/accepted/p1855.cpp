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
const int MAXN = 2e2 + 5;
int a[MAXN],b[MAXN],dp[MAXN][MAXN];
int n,m,t;
int main()
{
    cin >> n >> m >> t;
    for(int i = 1;i <= n;i++)
        scanf("%d%d",&a[i],&b[i]);
    for(int i = 1;i <= n;i++){
        for(int j = m;j >= a[i];j--){
            for(int k = t;k >= b[i];k--){
                dp[j][k] = max(dp[j][k],dp[j - a[i]][k - b[i]] + 1);
            }
        }
    }
    cout << dp[m][t] << endl;
    //system("pause");
    return 0;
}