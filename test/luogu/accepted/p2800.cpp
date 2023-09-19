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
const int MAXN = 1e6 + 5;
int a[MAXN];
int dp[MAXN];
int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 1;i <= n + 1;i++){
        dp[i] = dp[i - 1] + a[i];
        if(i >= 2)  dp[i] = min(dp[i],dp[i - 2] + a[i]);
        if(i >= 3)  dp[i] = min(dp[i],dp[i - 3] + a[i]);
    }
    cout << dp[n + 1] <<endl;
    //system("pause");
    return 0;
}