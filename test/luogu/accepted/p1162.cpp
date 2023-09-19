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
const int MAXN = 40;
int mp[MAXN][MAXN];
int n;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
struct node{
    int x,y;
};

bool check(int x,int y)
{
    if(x < 0 || y < 0 || x > n + 1 || y > n + 1|| mp[x][y] == 1 || mp[x][y] == 2)
        return false;
    return true;
}

void bfs()
{
    node tmp;
    tmp.x = 0;
    tmp.y = 0;
    mp[0][0] = 2;
    queue<node>q;
    q.push(tmp);
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        for(int i = 0;i < 4;i++){
            int tx = tmp.x + dx[i];
            int ty = tmp.y + dy[i];
            if(check(tx,ty)){
                node t;
                t.x = tx;
                t.y = ty;
                mp[tx][ty] = 2;
                q.push(t);
            }
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            scanf("%d",&mp[i][j]);
        }
    }
    bfs();
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(j != 1)
                printf(" ");
            if(mp[i][j] == 0)
                printf("2");
            else if(mp[i][j] == 2)
                printf("0");
            else 
                printf("1");
        }
        printf("\n");
    }
    return 0;
}   