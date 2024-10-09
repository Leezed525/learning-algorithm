//
// Created by Leezed on 2024/10/9.
//
#include "iostream"
#include "cstring"
#include "queue"

using namespace std;
const int maxn = 110;

int dx[] = {-1, 0, 0, 1,0};
int dy[] = {0, 1, -1, 0,0}; //N,E,W,S


int mp[maxn][maxn];
int vis[maxn][maxn][maxn];
//int vis[maxn][maxn][1010];按照题目要求的1010来开数组会超内存,不符合题目要求的A了

struct castle {
    int t, v;
    int dir;
} castles[maxn * maxn];

struct node {
    int x, y;
    int step;
};

int n, m, k, d;


void init() {
    memset(mp, -1, sizeof(mp));
    memset(castles, 0, sizeof(castles));
    memset(vis, 0, sizeof(vis));
}

bool check(int x, int y) {
    if (x >= 0 && x <= n && y >= 0 && y <= m) {
        return true;
    }
    return false;
}

void bfs() {
    queue<node> q;
    q.push({0, 0, 0});
    vis[0][0][0] = 1;
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        int x = now.x;
        int y = now.y;
        int step = now.step;
        if (x == n && y == m) {
            cout << step << endl;
            return;
        }
        for (int i = 0; i < 5; i += 1) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nstep = step + 1;
            if (check(nx, ny) && mp[nx][ny] == -1 && !vis[nx][ny][nstep] && nstep <= d) {//判断是否越界，是否有障碍物，是否访问过，是否超过时间
                //判断四个方向是否会被击中
                bool flag = 0;
                for (int j = 0; j < 4; j += 1) {
                    int tmpx = nx + dx[j];
                    int tmpy = ny + dy[j];
                    int castle_id = -1;
                    while (check(tmpx, tmpy)) {
                        if (mp[tmpx][tmpy] != -1) {
                            castle_id = mp[tmpx][tmpy];
                            break;
                        }
                        tmpx += dx[j];
                        tmpy += dy[j];
                    }
                    if (castle_id != -1 && castles[castle_id].dir == 3 - j) {//判断是否有城堡，城堡方向是否相反
                        //检查是否会被击中
                        int t = castles[castle_id].t;
                        int v = castles[castle_id].v;
                        int distance = abs(tmpx - nx) + abs(tmpy - ny);
                        if (distance % v == 0) { //判断子弹的速度能否击中
                            //如果能击中的话这颗子弹是什么时候发射的
                            int time = distance / v;//子弹飞行的时间
                            time = nstep - time;//子弹发射时间
                            if (time < 0) {
                                continue;
                            }
                            if (time % t == 0) {
                                flag = true;
                                break;
                            }
                        }
                    }
                }
                if (flag) {
                    continue;
                }
                vis[nx][ny][nstep] = 1;
                q.push({nx, ny, nstep});
            }
        }
    }
    cout << "Bad luck!" << endl;
}

int main() {
    while (cin >> n >> m >> k >> d) {
        init();
        for (int i = 0; i < k; i += 1) {
            int x, y, t, v;
            char dir;
            cin >> dir >> t >> v >> x >> y;
            castles[i].t = t;
            castles[i].v = v;
            if (dir == 'N') {
                castles[i].dir = 0;
            } else if (dir == 'E') {
                castles[i].dir = 1;
            } else if (dir == 'W') {
                castles[i].dir = 2;
            } else {
                castles[i].dir = 3;
            }
            mp[x][y] = i;
        }
        bfs();

    }
}