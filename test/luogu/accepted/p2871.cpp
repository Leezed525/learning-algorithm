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
const int MAXN = 13000;
int dp[MAXN];
int a[MAXN],b[MAXN];
int n,m;
int main()
{
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        scanf("%d%d",&a[i],&b[i]);
    }
    for(int i = 0;i < n;i++){
        for(int j = m;j >= a[i];j--){
            dp[j] = max(dp[j],dp[j - a[i]] + b[i]);
        }
    }
    cout << dp[m] << endl;
    //system("pause");
    return 0;
}