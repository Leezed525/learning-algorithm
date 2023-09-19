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
const double PI = acos(-1);
const int MAXN = 1e3 + 10;
int dp[MAXN];
int v[MAXN],w[MAXN];
int main()
{
    int n,m;
    cin >> n >>m;
    for(int i = 1;i <= n;i++){
        cin >> v[i] >> w[i];
    }
    for(int i = 1;i <= n;i++)
        for(int j = m;j >= v[i] ;j--){
            dp[j] = max(dp[j],dp[j - v[i]] + w[i]);
        }
    cout << dp[m] << endl;
    //system("pause");
    return 0;
}