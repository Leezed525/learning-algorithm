//
// Created by Leezed on 2024/12/10.
//
#include "iostream"
#include "cstring"
#include "vector"
#include "queue"


using namespace std;


const int maxn = 1005;


struct edge {
    int to;
    int cost;
};

vector<edge> e[maxn];


struct node {
    int x, dis;

    //从小到大排序
    bool operator<(node p) const {
        return dis > p.dis;
    }

    node(int x, int dis) : x(x), dis(dis) {

    }
};


int dis[maxn];
int vis[maxn];


// djikstra
int dijkstra(int start) {
    priority_queue<node> q;
    dis[start] = 0;
    q.push(node(start, 0));
    while (!q.empty()) {
        node tmp = q.top();
        q.pop();
        int x = tmp.x;
        if (vis[x]) {
            continue;
        }
        vis[x] = 1;

        for (int i = 0; i < e[x].size(); i += 1) {
            int to = e[x][i].to;
            int cost = e[x][i].cost;
            if (dis[to] > dis[x] + cost) {
                dis[to] = dis[x] + cost;
                q.push(node(to, dis[to]));
            }
        }
    }

    return dis[0];

}

int main() {
    int N, T;

    cin >> T >> N;
    for (int i = 0; i < T; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge tmp;
        tmp.to = b;
        tmp.cost = c;
        e[a].push_back(tmp);
        tmp.to = a;
        e[b].push_back(tmp);
    }
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));

    dijkstra(N);

    cout << dis[1] << endl;

    return 0;
}