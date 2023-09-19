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
int a[MAXN];
int sum[MAXN];
int dp[MAXN];
int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        sum[i] = sum[i - 1] + a[i];
        if(sum[i] >= 0){
            dp[i] = 1;
        }
    }
    if(sum[n] < 0){
        printf("Impossible\n");
        return 0;
    }
    for(int i = 1;i <= n;i++){
        if(sum[i] < 0){
            continue;
        }
        for(int j = 0;j < i;j++){
            if(sum[i] - sum[j] >= 0){
                dp[i] = max(dp[i],dp[j] + 1);
            }
        }
    }
    cout << dp[n] << endl;
    //system("pause");
    return 0;
}