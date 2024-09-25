//
// Created by Leezed on 2024/9/24.
//
#include "iostream"
#include "cstring"
#include "queue"

using namespace std;

const int maxn = 1e3 + 5;
int origin_map[maxn][maxn];
int fire_map[maxn][maxn];
int visited[maxn][maxn];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int R, C;
int fire_num = 0;

struct node {
    int x;
    int y;
    int step;

    node(int x, int y, int step) {
        this->x = x;
        this->y = y;
        this->step = step;
    }

};

queue<node> fire_q;

bool check(int x, int y) {
    if (x < 0 || x >= R || y < 0 || y >= C || origin_map[x][y] == 0) {
        return false;
    }
    return true;
}


void fire_bfs() {
    while (!fire_q.empty()) {
        node front = fire_q.front();
        fire_q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = front.x + dx[i];
            int ny = front.y + dy[i];
            if (check(nx, ny) && (!visited[nx][ny] || fire_map[nx][ny] > front.step + 1)) {
                fire_map[nx][ny] = front.step + 1;
                visited[nx][ny] = 1;
                fire_q.push(node(nx, ny, front.step + 1));
            }
        }
    }
}

void ming_bfs(int x, int y) {
    queue<node> q;
    q.push(node(x, y, 0));
    visited[x][y] = 1;
    while (!q.empty()) {
        node front = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = front.x + dx[i];
            int ny = front.y + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                cout << front.step + 1 << endl;
                return;
            }
            if (check(nx, ny) && visited[nx][ny] == 0 && fire_map[nx][ny] > front.step + 1) {
                visited[nx][ny] = 1;
                q.push(node(nx, ny, front.step + 1));
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> R >> C;
        fire_num = 0;
        int start_x, start_y;
        memset(fire_map, 0x3f, sizeof(fire_map));
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < R; i += 1) {
            for (int j = 0; j < C; j += 1) {
                char c;
                cin >> c;
                if (c == '#') {
                    origin_map[i][j] = 0;
                } else if (c == '.') {
                    origin_map[i][j] = 1;
                } else if (c == 'J') {
                    origin_map[i][j] = 0;
                    start_x = i;
                    start_y = j;
                } else if (c == 'F') {
                    origin_map[i][j] = 0;
                    fire_q.push(node(i, j, 0));
                    fire_map[i][j] = 0;
                } else if (c == '\n') {
                    j -= 1;
                }
            }
        }
        fire_bfs();
        memset(visited, 0, sizeof(visited));
        ming_bfs(start_x, start_y);
    }
    return 0;
}


/*
2
4 4
####
#JF#
#..#
#..#
3 3
###
#J.
#.F
*/