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
int n,k;
int ans = 0;
void dfs(int sum,int counts,int fa)
{
    if(counts == k){
        if(sum == n){
            ans++;
        }
        return ;
    }
    if(sum >= n){
        return ;
    }   
    for(int i = fa;sum + (k - counts) * i <= n;i++){
        dfs(sum + i,counts + 1,i);
    }
    return ;
}

int main()
{
    cin >> n >> k;
    dfs(0,0,1);
    cout << ans << endl;
    return 0;
}