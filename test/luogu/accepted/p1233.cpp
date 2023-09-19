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
const int MAXN = 5e3+10;
int dp[MAXN];
struct node{
    int l,w;
}a[MAXN];

bool cmp(node a,node b)
{
    if(a.l == b.l){
        return a.w > b.w;
    }
    return a.l > b.l;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d%d",&a[i].l,&a[i].w);
    }
    sort(a + 1,a + 1 + n,cmp);
    int ans = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j < i;j++){
            if(a[i].l > a[j].l || a[i].w > a[j].w){
                dp[i] = max(dp[i],dp[j] + 1);
            }
        }
        dp[i] = max(dp[i],1);
        ans = max(dp[i],ans);
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}