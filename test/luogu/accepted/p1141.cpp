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
int mp[MAXN][MAXN];
int path[MAXN * MAXN][2];
int ans[MAXN][MAXN];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n,m,len;


bool check(int x,int y)
{
    if(x <= 0 || y <= 0 || x > n || y > n || ans[x][y] != 0)
        return false;
    return true;
}

void dfs(int x,int y)
{
    path[len][0] = x;
    path[len++][1] = y;
    ans[x][y] = 1;
    for(int i = 0;i < 4;i++){
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(check(tx,ty) && mp[tx][ty] != mp[x][y]){
            dfs(tx,ty);
        }
    }
    return ;
}

int main()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            scanf("%1d",&mp[i][j]);
        }
    }
    for(int i = 0;i < m;i++){
        len = 0;
        int a,b;
        scanf("%d%d",&a,&b);
        if(ans[a][b] != 0)
            printf("%d\n",ans[a][b]);
        else{
            dfs(a,b);
            for(int i = 0;i < len;i++){
                ans[path[i][0]][path[i][1]] = len;
            }
            printf("%d\n",ans[a][b]);
        }
    }
    return 0;
}
