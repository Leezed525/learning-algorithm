#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
//*(int(*)[10])arr_name
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
const int MAXN = 1e3 + 10;
int m,n;
struct edge {
    int u, t, w;
    edge(int a, int b, int c) { u = a, t = b, w = c; }
};

vector<edge> g[MAXN];
struct snode {
    int id;
    int dis;
    snode(int a, int b) { id = a, dis = b; }
    bool operator < (const snode &t)const {
        return dis > t.dis;
    }
};

void dijkstra(){
    int s = 1;
    int dis[n + 1];
    int vis[n + 1];
    for(int i = 1;i <= n;i++){
        dis[i] = INF;
        vis[i] = 0;
    }
    dis[1] = 0;
    priority_queue<snode>q;
    q.push(snode(1,0));
    while(!q.empty()){
        snode u = q.top();
        q.pop();
        if(vis[u.id])
            continue;
        vis[u.id] = 1;
        for(int i = 0;i < g[u.id].size();i++){
            edge tmp = g[u.id][i];
            if(vis[tmp.t])
                continue;
            if(dis[tmp.t] > dis[tmp.u] + tmp.w){
                dis[tmp.t] = dis[tmp.u] + tmp.w;
            }
            q.push(snode(tmp.t,dis[tmp.t]));
        }
    }
    cout << dis[n] <<endl;
}

int main() {
    cin >> m >> n;
    for(int i = 1;i <= m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a].push_back(edge(a,b,c));
        g[b].push_back(edge(b,a,c));
    }
    dijkstra();
    // system("pause");
    return 0;
}