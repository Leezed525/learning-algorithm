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
int sum[MAXN];
int a[MAXN];
int dp1[MAXN][MAXN],dp2[MAXN][MAXN];
int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        a[i + n] = a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for(int i = n + 1;i <= 2 * n;i++){
        sum[i] = sum[i - 1] + a[i];
    }
    for(int len = 1;len < n;len++){
        for(int i = 1;i <= 2 * n - len;i++){
            int j = i + len;
            dp1[i][j] = 1e9;
            for(int k = i;k < j;k++){
                dp1[i][j] = min(dp1[i][j],dp1[i][k] + dp1[k + 1][j] + sum[j] - sum[i - 1]);
                dp2[i][j] = max(dp2[i][j],dp2[i][k] + dp2[k + 1][j] + sum[j] - sum[i - 1]);
            }
        }
    }
    int minn = INF,maxn = 0;
    for(int i = 1;i <= n;i++){
        minn = min(minn,dp1[i][i + n - 1]);
    }
    for(int i = 1;i <= n;i++){
        maxn = max(maxn,dp2[i][i + n - 1]);
    }
    cout << minn << endl << maxn << endl;
    //system("pause");
    return 0;
}