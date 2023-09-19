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
const int MAXN = 4e2 + 5;
int n,m;
int sx,sy;
int mp[MAXN][MAXN];
int dx[] = {2,1,-1,-2,-2,-1,1,2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};

struct node{
    int x,y;
};

bool check(int x,int y)
{
    if(x <= 0 || y <= 0 || x > n || y > m || mp[x][y] != -1)
        return false;
    return true;
}

void bfs()
{
    node tmp;
    tmp.x = sx;
    tmp.y = sy;
    mp[sx][sy] = 0;
    queue<node>q;
    q.push(tmp);
    while(!q.empty()){
        tmp = q.front();q.pop();
        for(int i = 0;i < 8;i++){
            int tx = tmp.x + dx[i];
            int ty = tmp.y + dy[i];
            if(check(tx,ty)){
                mp[tx][ty] = mp[tmp.x][tmp.y] + 1;
                node z;
                z.x = tx;
                z.y = ty;
                q.push(z);
            }
        }
    }
}

int main()
{
    memset(mp,-1,sizeof(mp));
    cin >> n >> m >> sx >> sy;
    bfs();
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            printf("%-5d",mp[i][j]);
        }
        printf("\n");
    }
    return 0;
}