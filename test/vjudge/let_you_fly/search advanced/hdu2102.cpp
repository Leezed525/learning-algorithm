//
// Created by Leezed on 2024/11/4.
//
#include "cstring"
#include "iostream"
#include "queue"

using namespace std;
const int maxn = 12;
int mp[2][maxn][maxn];
int vis[2][maxn][maxn];
int n, m, t;
int ex, ey, ez;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct node {
    int x, y, z;
    int step;
};


void print_mp() {
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            printf("%2d", mp[0][i][j]);
        }
        printf("\n");
    }
    cout << endl;

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            printf("%2d", mp[1][i][j]);
        }
        printf("\n");
    }
}

bool check(int x, int y, int z) {
    if (x < 0 || x >= n || y < 0 || y >= m || mp[z][x][y] == -1 || vis[z][x][y] == 1) {
        return false;
    }
    return true;

}


void init() {
    memset(mp, 0, sizeof(mp));
    memset(vis, 0, sizeof(vis));
}

void bfs(int sx, int sy, int sz) {
    queue<node> q;
    q.push({sx, sy, sz, 0});
    vis[sz][sx][sy] = 1;
    if (sx == ex && sy == ey && sz == ez) {
        cout << "YES" << endl;
        return;
    }
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        int x = now.x;
        int y = now.y;
        int z = now.z;
        int step = now.step;
        if (step > t) {
            cout << "NO" << endl;
            return;
        }
        for (int i = 0; i < 4; i += 1) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z;
            //判断是不是传送门
            if (mp[nz][nx][ny] == 1) {
                nz = 1 - nz;
                if(mp[nz][nx][ny] == 1) {
                    continue;
                }
            }
            if (check(nx, ny, nz)) {
                if (nx == ex && ny == ey && nz == ez && step + 1 <= t) {
                    cout << "YES" << endl;
                    return;
                }
                vis[nz][nx][ny] = 1;
                q.push({nx, ny, nz, step + 1});
            }
        }
    }
    cout << "NO" << endl;
    return;
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        init();
        int sx, sy, sz;
        cin >> n >> m >> t;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    char ch;
                    scanf(" %c", &ch);
                    if (ch == 'S') {
                        mp[i][j][k] = 0;
                        sx = j;
                        sy = k;
                        sz = i;
                    } else if (ch == '#') {
                        mp[i][j][k] = 1;
                    } else if (ch == '*') {
                        mp[i][j][k] = -1;
                    } else if (ch == 'P') {
                        mp[i][j][k] = 0;
                        ex = j;
                        ey = k;
                        ez = i;
                    } else if (ch == '.') {
                        mp[i][j][k] = 0;
                    }
                }
            }
        }
        bfs(sx, sy, sz);
//        print_mp();
    }
    return 0;
}

/*
2
5 5 14
S*#*.
.#...
.....
****.
...#.

..*.P
#.*..
***..
...*.
*.#..

5 5 14
S*#*.
.#...
.....
****.
...#.

..*.P
#.*..
***..
...*.
*.#..
*/