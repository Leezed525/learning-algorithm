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
const int MAXN = 1e2 + 5;
int mp[MAXN][MAXN];
int ans[MAXN][MAXN];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n,m;

bool check(int x,int y)
{
    if(x <= 0 || y <= 0 || x > n || y > m )
        return false;
    return true;
}

int dfs(int x,int y)
{
    if(ans[x][y] > 0)
        return ans[x][y];
    ans[x][y] = 1;
    for(int i = 0;i < 4;i++){
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(check(tx,ty) && mp[x][y] > mp[tx][ty]){
            ans[x][y] = max(ans[x][y],dfs(tx,ty) + 1);
        }
    }
    return ans[x][y];
}

int main()
{
    cin >> n >>m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            scanf("%d",&mp[i][j]);
        }
    }
    int maxn = -INF;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            maxn = max(maxn,dfs(i,j));
        }
    }
    cout << maxn << endl;
    return 0;
}