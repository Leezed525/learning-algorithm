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
int a[] = {1,2,3,5,10,20};
int b[6];
const int MAXN = 10100;
int dp[MAXN];
int main()
{
    dp[0] = 1;
    for(int i = 0;i < 6;i++){
        scanf("%d",b + i);
    }
    int maxn = 0;
    for(int i = 0;i < 6;i++){
        for(int j = 1;j <= b[i];j++){
            for(int k = maxn;k >= 0;k--){
                if(dp[k]){
                    dp[k + a[i]] = 1;
                    if(k + a[i] > maxn){
                        maxn = k + a[i];
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= 1000;i++){
        if(dp[i])
            ans++;
    }
    printf("Total=%d\n",ans);
    //system("pause");
    return 0;
}