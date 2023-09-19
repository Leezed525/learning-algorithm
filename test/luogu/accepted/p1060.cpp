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
const int MAXN = 30;
int v[MAXN],w[MAXN];
int dp[30010];

int main()
{
    int m,n;
    cin >> m >> n;
    for(int i = 0;i < n;i++){
        scanf("%d%d",&v[i],&w[i]);
        w[i] *= v[i];
    }
    for(int i = 0;i < n;i++){
        for(int j = m;j >= v[i];j--){
            dp[j] = max(dp[j - v[i]] + w[i],dp[j]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}