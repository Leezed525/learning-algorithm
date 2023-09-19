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
struct node{
    int a,b,c;
}people[MAXN];
int dp[MAXN][MAXN];
int n,m,x;
int main()
{
    cin >> m >> x >> n;
    for(int i = 0;i < n;i++){
        scanf("%d%d%d",&people[i].b,&people[i].c,&people[i].a);
    }
    for(int i = 0;i < n;i++){
        for(int j = m;j >= people[i].b;j--){
            for(int k = x;k >= people[i].c;k--){
                dp[j][k] = max(dp[j][k],dp[j - people[i].b][k - people[i].c] + people[i].a);
            }
        }
    }
    cout << dp[m][x] <<endl;
    //system("pause");
    return 0;
}