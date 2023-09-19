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
const int MAXM = 5e5 + 10; 
const int MAXN = 1e4 + 10;
int dis[MAXN],biaoji[MAXN],head[MAXN],cnt = 1;
struct edge1{
    int u,t,w;
    int next;
}edge[MAXM];

void addedge(int u,int t,int w)
{
    edge[cnt].u = u;
    edge[cnt].t = t;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
int n,m,s;

void spfa()
{
    queue<int>q;
    for(int i = 1;i <= n;i++){
        dis[i] = INF;
        biaoji[i] = 0;
    }
    q.push(s);
    biaoji[s] = 1;
    dis[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        biaoji[u] = 0;
        for(int i = head[u];i != 0;i = edge[i].next){
            int v = edge[i].t;
            if(dis[v] > dis[u] + edge[i].w){
                dis[v] = dis[u] + edge[i].w;
                if(biaoji[v] == 0){
                    biaoji[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m >> s;
    for(int i = 0;i < m;i++){
        int u,t,w;
        scanf("%d%d%d",&u,&t,&w);
        addedge(u,t,w);
    }
    spfa();
    for(int i = 1;i <= n;i++){
        printf("%d%c",dis[i] == INF?(1<<31) - 1:dis[i],i == n?'\n':' ');
    }
    //system("pause");
    return 0;
}