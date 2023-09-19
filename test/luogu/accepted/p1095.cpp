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
const int MAXN = 3e5 + 10;
int dp[MAXN];
int main()
{
    int m,s,t;
    cin >> m >> s >>t;
    for(int i = 1;i <= t;i++){
        if(m >= 10){
            dp[i] = dp[i - 1] + 60;
            m -= 10;
        }
        else{
            dp[i] = dp[i - 1];
            m += 4;
        }
    }
    for(int i = 1;i <= t;i++){
        dp[i] = max(dp[i],dp[i - 1] + 17);
        if(dp[i] >= s){
            printf("Yes\n%d\n",i);
            return 0;
        }
    }
    printf("No\n%d\n",dp[t]);
    //system("pause");
    return 0;
}