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
const int MAXN = 1e2 + 5;
int a[MAXN],dp1[MAXN],dp2[MAXN];
int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }
    dp1[1] = dp2[n] =  1;
    for(int i = 2;i <= n;i++){
        for(int j = 1;j < i;j++){
            if(a[i] > a[j]){
                dp1[i] = max(dp1[i],dp1[j] + 1);
            }
        }
        dp1[i] = max(dp1[i],1);
    }
    for(int i = n - 1;i >= 1;i--){
        for(int j = n;j > i;j--){
            if(a[i] > a[j]){
                dp2[i] = max(dp2[i],dp2[j] + 1);
            }
        }
        dp2[i] = max(dp2[i],1);
    }
    int maxn = 0;
    for(int i = 1;i <= n;i++){
        maxn = max(maxn,dp2[i] + dp1[i] - 1);
    }
    cout << n - maxn << endl;
    // for(int i = 1;i <= n;i++){
    //     printf("%d ",dp1[i]);
    // }
    // cout << endl;
    // for(int i = 1;i <= n;i++){
    //     printf("%d ",dp2[i]);
    // }
    //system("pause");
    return 0;
}