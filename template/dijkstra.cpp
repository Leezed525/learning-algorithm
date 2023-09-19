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
const int MAXN = 1e2 + 10;
int n,m;
struct edge{
    int u,t,w;
    edge(int a,int b,int c){
        u = a;
        t = b;
        w = c;
    }
};
struct s_node{
    int id,dis;
    s_node(int a,int b){
        id = a;
        dis = b;
    }
    bool operator < (const s_node &t)const{
        return dis > t.dis;
    }
};
vector<edge>g[MAXN];
void dijkstra()
{
    int s = 1;
    int dis[MAXN];
    bool biaoji[MAXN];
    for(int i = 1;i <= n;i++){
        dis[i] = INF;
        biaoji[i] = false;
    }
    dis[s] = 0;
    priority_queue<s_node>q;
    q.push(s_node(s,0));
    while(!q.empty()){
        s_node u = q.top();q.pop();
        if(biaoji[u.id])
            continue;
        biaoji[u.id] = 1;
        for(int i = 0;i < g[u.id].size();i++){
            edge y = g[u.id][i];
            if(biaoji[y.t])
                continue;
            if(dis[y.t] > y.w + dis[y.u]){
                dis[y.t] = y.w + dis[y.u];
            }
            q.push(s_node(y.t,dis[y.t]));
            //pre[y.to] = u.id;
        }
    }
    for(int i = 1;i <= n;i++){
        printf("%d%c",dis[i],i == n?'\n':' ');
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a].push_back(edge(a,b,c));
        g[b].push_back(edge(b,a,c));
    }
    dijkstra();
    //system("pause");
    return 0;
}