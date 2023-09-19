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
int a[25];
void dabiao()
{
    for(int i = 1;i <= 20;i++){
        a[i] = i*i*i*i;
    }
}
int n;
const int MAXN = 1e5 + 5;
int dp[MAXN];
int main()
{
    dabiao();
    cin >> n;
    memset(dp,0x3f,sizeof(dp));
    dp[0] = 0;
    for(int i = 1;a[i] <= n;i++){
        for(int j = a[i];j <= n;j++){
            dp[j] = min(dp[j - a[i]] + 1,dp[j]);
        }
    }
    cout << dp[n] << endl;
    //system("pause");
    return 0;
}