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
const int MAXN = 1e3 + 5;
LL lose[MAXN],win[MAXN],use[MAXN];
LL dp[MAXN];
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        scanf("%lld%lld%lld",&lose[i],&win[i],&use[i]);
    }
    for(int i = 1;i <= n;i++){
        for(int j = m;j >= 0;j--){
            if(j >= use[i])
                dp[j] = max(dp[j] + lose[i],dp[j - use[i]] + win[i]);
            else
                dp[j] = max(dp[j],dp[j] + lose[i]);
        }
    }
    cout << dp[m] * 5 << endl;
    //system("pause");
    return 0;
}