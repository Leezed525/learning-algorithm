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
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
const int MAXN = 1e2 + 5;
int sx,sy,ex,ey,n,m;
char ch;
int mp[MAXN][MAXN];
int biaoji[MAXN][MAXN];
struct node{
    int x,y;
    int dir;
    int step;
};

bool check(int x,int y)
{
    if(x <= 0 || y <= 0 || x > n || y > m || mp[x][y] == 1 || biaoji[x][y] == 1){
        return false;
    }
    return true;
}


void bfs()
{
    node tmp;
    tmp.x = sx;
    tmp.y = sy;
    if(ch == 'N')
        tmp.dir = 0;
    else if(ch == 'E')
        tmp.dir = 1;
    else if(ch == 'S')
        tmp.dir = 2;
    else
        tmp.dir = 3;
    tmp.step = 0;
    queue<node>q;
    q.push(tmp);
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        biaoji[tmp.x][tmp.y] = 1;
        if(tmp.x == ex && tmp.y == ey){
            printf("%d\n",tmp.step);
            return ;
        }
        for(int i = 1;i <= 5;i++){
            if(i <= 3){
                int tx = tmp.x + i * dx[tmp.dir];
                int ty = tmp.dir + i * dy[tmp.dir];
                if(check(tx,ty)){
                    node z;
                    z.x = tx;
                    z.y = ty;
                    z.dir = tmp.dir;
                    z.step = tmp.step + 1;
                    q.push(z);
                }
            }
            else if(i == 4){
                node z;
                z.x = tmp.x;
                z.y = tmp.y;
                z.dir = (tmp.dir + 1) % 4;
                z.step = tmp.step + 1;
                q.push(z);
            }
            else{
                node z;
                z.x = tmp.x;
                z.y = tmp.y;
                z.dir = (tmp.dir + 3) % 4;
                z.step = tmp.step + 1;
                q.push(z);
            }
        }
    }
    printf("-1\n");
    return ;
}

int main()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            scanf("%d",&mp[i][j]);
        }
    }
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    scanf(" %c",&ch);
    bfs();
    return 0;
}
