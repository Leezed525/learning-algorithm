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
const int MAXN = 1010;
int dp[MAXN];
int main()
{
    int t,m;
    cin >> t >> m;
    int a[m],b[m];
    for(int i = 0;i < m;i++){
        scanf("%d%d",&a[i],&b[i]);
    }
    for(int i = 0;i < m;i++){
        for(int j = t;j >= a[i];j--){
            dp[j] = max(dp[j],dp[j - a[i]] + b[i]);
        }
    }
    cout << dp[t] << endl;
    system("pause");
    return 0;
}