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
const int N = 55;
struct node{
    LL a,b,c;
}food[N];
const int MAXN = 1e5 + 5;
LL dp[MAXN];
bool cmp(node a,node b)
{
    return a.c * b.b < a.b * b.c;
}
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= m;i++)
        scanf("%lld",&food[i].a);
    for(int i = 1;i <= m;i++)
        scanf("%lld",&food[i].b);
    for(int i = 1;i <= m;i++)
        scanf("%lld",&food[i].c);
    sort(food + 1,food + 1 + m,cmp);
    LL maxn = -INF;
    for(int i = 1;i <= m;i++){
        for(int j = n;j >= food[i].c;j--){
            dp[j] = max(dp[j],dp[j - food[i].c] + food[i].a - j * food[i].b);
            maxn = max(maxn,dp[j]);
        }
    }
    cout << maxn <<endl;
    //system("pause");
    return 0;
}