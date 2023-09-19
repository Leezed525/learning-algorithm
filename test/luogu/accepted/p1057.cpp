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
const int MAXN = 50;
int ans = 0;
int f[MAXN][MAXN];
void dfs(int now,int counts)
{
    f[now][counts] = 0;
    if(counts == m){
        if(now == 0){
            f[now][counts] = 1;
        }
        return ;
    }
    if(now > (m - counts) && n - now > (m - counts) ){
        return ;
    }
    if(f[(now + n - 1) % n][counts + 1] == -1)dfs((now + n - 1) % n,counts + 1);
    if(f[(now + 1) % n][counts + 1] == -1)dfs((now + 1) % n,counts + 1);
    f[now][counts] = f[(now + n - 1) % n][counts + 1] + f[(now + 1) % n][counts + 1];
}

int main()
{
    memset(f,-1,sizeof(f));
    cin >> n >> m;
    dfs(0,0);
    cout << f[0][0] << endl;
    return 0;
}
