//
// Created by Leezed on 2025/8/19.
//
#include "bits/stdc++.h"

using namespace std;


int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

const int maxn = 5e2 + 10;
int mp[maxn][maxn];
int vis[maxn][maxn]; //标记是否来过这个点，并记录来到这个点的时候的转移次数
int sx, sy, ex, ey;
int n, m;

bool check(int x, int y, int count) {
    if (x <= 0 || x > n || y <= 0 || y > m) return false;
    if (mp[x][y] == 1) return false;
    if (vis[x][y] != -1 && vis[x][y] <= count) return false; //如果来过这个点，并且转移次数小于等于当前的转移次数，则不需要再来
    return true;
}

struct node {
    int x, y;
    int count;
    int step;

    node() : x(0), y(0), count(0), step(0) {}

    node(int x, int y, int count, int step) : x(x), y(y), count(count), step(step) {}
};

void bfs() {
    queue<node> q;
    q.emplace(sx, sy, 0, 0);
    vis[sx][sy] = 0; //起点的转移次数为0
    while (!q.empty()) {
        node cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i += 1) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (check(nx, ny, cur.count)) {
                if (nx == ex && ny == ey) {
                    cout << cur.step + 1 << endl;
                    return;
                }
                vis[nx][ny] = cur.count;
                q.emplace(nx, ny, cur.count, cur.step + 1);
            }
        }
        if (cur.count < 5) {
            int nx = n + 1 - cur.x;
            int ny = m + 1 - cur.y;
            if (check(nx, ny, cur.count + 1)) {
                if (nx == ex && ny == ey) {
                    cout << cur.step + 1 << endl;
                    return;
                }
                vis[nx][ny] = cur.count + 1;
                q.emplace(nx, ny, cur.count + 1, cur.step + 1);
            }
        }
    }

    cout << -1 << endl;
}

void print_vis() {
    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= m; j += 1) {
            cout << vis[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    cin >> n >> m;
    string s;
    for (int i = 1; i <= n; i += 1) {
        cin >> s;
        for (int j = 1; j <= m; j += 1) {
            vis[i][j] = -1;
            if (s[j - 1] == '.') {
                mp[i][j] = 0;
            }else if (s[j - 1] == '#') {
                mp[i][j] = 1;
            }else{
                mp[i][j] = 0;
                if (s[j - 1] == 'S') {
                    sx = i;
                    sy = j;
                } else if (s[j - 1] == 'E') {
                    ex = i;
                    ey = j;
                }
            }
        }
    }

    bfs();
//    print_vis();


    return 0;
}