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
const int MAXN = 1510;
char mp[MAXN][MAXN];
int biaoji[MAXN][MAXN][3];
int n,m,sx,sy;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int allflag = 0;
struct node{
    int x,y;
    node(int _x,int _y){
        x = _x;
        y = _y;
    }
};

void dfs(int x,int y,int xx,int yy)
{
    if(allflag)
        return ;
    if(biaoji[x][y][0] && (biaoji[x][y][1] != xx || biaoji[x][y][2] != yy)){
        allflag = 1;
        return ;
    }
    biaoji[x][y][0] = xx;
    biaoji[x][y][1] = yy;
    biaoji[x][y][2] = 1;
    for(int i = 0;i < 4;i++){
        int tx = (x + dx[i] + n) % n;
        int ty = (y + dy[i] + m) % m;
        int tmpx = xx + dx[i];
        int tmpy = yy + dy[i];
        if(mp[tx][ty] == '.'){
            if(biaoji[tx][ty][0] != tmpx || biaoji[tx][ty][1] != tmpy || !biaoji[tx][ty][2])
                dfs(tx,ty,tmpx,tmpy);
            if(allflag){
                return ;
            }
        }
    }
}

int main()
{
    while(cin >> n >> m){
        allflag = 0;
        memset(biaoji,0,sizeof(biaoji));
        memset(mp,0,sizeof(mp));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                char ch;
                cin >> ch;
                if(ch == 'S'){
                    sx = i;
                    sy = j;
                    mp[i][j] = '.';
                }
                else{
                    mp[i][j] = ch;
                }
            }
        }
        dfs(sx,sy,sx,sy);
        if(allflag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    //system("pause");
    return 0;
}