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
const int MAXN = 3000;
int n,m,start,goal;
struct edge{
    int u,t,w;
    edge(int a,int b,int c){
        u = a;
        t = b;
        w = c;
    }
};

vector<edge>g[MAXN];

struct s_node{
    int id,dis;
    s_node(int a,int b){
        id = a;
        dis = b;
    }
    bool operator < (const s_node &t)const {
        return dis > t.dis;
    }
};

void dijkstra()
{
    int dis[n + 1];
    bool biaoji[n + 1];
    for(int i = 1;i <= n;i++){
        dis[i] = INF;
        biaoji[i] = 0;
    }
    int s = start;
    dis[s] = 0;
    priority_queue<s_node>q;
    q.push(s_node(s,dis[s]));
    while(!q.empty()){
        s_node u = q.top();q.pop();
        if(biaoji[u.id])
            continue;
        biaoji[u.id] = 1;
        for(int i = 0;i < g[u.id].size();i++){
            edge y = g[u.id][i];
            if(biaoji[y.t])
                continue;
            if(dis[y.t] > dis[y.u] + y.w)
                dis[y.t] = dis[y.u] + y.w;
            q.push(s_node(y.t,dis[y.t]));
        }
    }
    cout << dis[goal] << endl;
}
int main()
{
    cin >> n >> m >> start >> goal;
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