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
const int MAXN = 10 + 5;
int mp[MAXN][MAXN][MAXN];
int vis[MAXN][MAXN][MAXN];
int n;
int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,1,-1};
int sx,sy,sz,ex,ey,ez;
struct node{
    int x,y,z;
    int len;
    node(int a,int b,int c,int d){
        x = a;
        y = b;
        z = c;
        len = d;
    }
};

bool check(int x,int y,int z)
{
    if(x<0 || y<0 || z<0 || x>= n || y >= n || z >= n || mp[x][y][z] == 1 || vis[x][y][z] == 1)
        return false;
    return true;
}

void init()
{
    memset(mp,0,sizeof(mp));
    memset(vis,0,sizeof(vis));
}

int bfs()
{
    queue<node>q;
    q.push(node(sx,sy,sz,0));
    while(!q.empty()){
        node tmp = q.front();q.pop();
        vis[tmp.x][tmp.y][tmp.z] = 1;
        if(tmp.x == ex && tmp.y == ey && tmp.z == ez)
            return tmp.len;
        for(int i = 0;i < 6;i++){
            int tx = tmp.x + dx[i];
            int ty = tmp.y + dy[i];
            int tz = tmp.z + dz[i];
            if(check(tx,ty,tz)){
                q.push(node(tx,ty,tz,tmp.len + 1));
            }
        }
    }
    return -1;
}

int main()
{
    string s;
    while(cin >> s >> n){
        init();
        getchar();
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                for(int k = 0;k < n;k++){
                    char ch;
                    scanf("%c",&ch);
                    if(ch == 'O'){
                        mp[j][k][i] = 0;
                    }
                    else{
                        mp[j][k][i] = 1;
                    }
                }
                getchar();
            }
        }
        scanf("%d%d%d",&sx,&sy,&sz);
        scanf("%d%d%d",&ex,&ey,&ez);
        cin >> s;
        int ans = bfs();
        if(ans == -1)
            cout << "NO ROUTE" <<endl;
        else 
            cout << n << " " << ans << endl;
    }
    //system("pause");
    return 0;
}