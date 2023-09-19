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
int n,m;
const int MAXN = 1e2 + 5;
int a[MAXN][MAXN];
int dp[MAXN][MAXN];
int main()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int maxn = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(a[i][j] == 1){
                dp[i][j] = min(min(dp[i - 1][j - 1],dp[i - 1][j]),dp[i][j - 1]) + 1;
                if(dp[i][j] > maxn)
                    maxn = dp[i][j];
            }
        }
    }
    cout << maxn << endl;
    //system("pause");
    return 0;
}