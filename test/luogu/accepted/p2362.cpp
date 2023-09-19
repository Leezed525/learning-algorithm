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
const int MAXN = 25;
int dp[MAXN];
int a[MAXN];
int num[MAXN];
int main()
{
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        memset(dp,0,sizeof(dp));
        memset(num,0,sizeof(num));
        for(int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        for(int i = 1;i <= n;i++){
            int maxn = 1;
            for(int j = i - 1;j >= 1;j--){
                if(a[i] >= a[j]){
                    dp[i] = max(dp[j] + 1,dp[i]);
                    if(dp[i] > maxn){
                        maxn = dp[i];
                        num[i] = num[j];
                    }
                    else if(dp[j] + 1 == maxn ){
                        num[i]++;
                    }
                }
            }
            if(num[i] == 0)
                num[i] = 1;
            dp[i] = max(1,dp[i]);
        }
        int ans1 = 0,ans2;
        for(int i = 1;i <= n;i++){
            if(dp[i] > ans1){
                ans1 = dp[i];
                ans2 = num[i];
            }
            else if(ans1 == dp[i]){
                ans2 == num[i];
            }
        }
        cout << ans1 << " " << ans2 << endl;
    }

    //system("pause");
    return 0;
}