//
// Created by Leezed on 2024/9/25.
//
#include "iostream"
#include "cstring"
#include "queue"

using namespace std;

const int maxn = 2e2 + 5;
int origin_map[maxn][maxn];
int visited[maxn][maxn];
int n, m;
int kfc_num;
int kfc[maxn * maxn][2];
int y_distance[maxn * maxn];
int m_distance[maxn * maxn];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


struct node {
    int x, y;
    int step;

    node(int x, int y, int step) : x(x), y(y), step(step) {}
};


void init() {
    memset(origin_map, 0, sizeof(origin_map));
    kfc_num = 0;
    memset(kfc, 0, sizeof(kfc));
    memset(y_distance, 0x3f, sizeof(y_distance));
    memset(m_distance, 0x3f, sizeof(m_distance));
}

void bfs(int x, int y, char type) {
    memset(visited, 0, sizeof(visited));
    queue<node> q;
    visited[x][y] = 1;
    q.push(node(x, y, 0));
    while (!q.empty()) {
        node front = q.front();
        q.pop();
        for (int i = 0; i < kfc_num; i += 1) {
            if (front.x == kfc[i][0] && front.y == kfc[i][1]) {
                if (type == 'Y') {
                    y_distance[i] = min(y_distance[i], front.step);
                } else {
                    m_distance[i] = min(m_distance[i], front.step);
                }
                break;
            }
        }
        for (int i = 0; i < 4; ++i) {
            int nx = front.x + dx[i];
            int ny = front.y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && origin_map[nx][ny] == 1 && visited[nx][ny] == 0) {
                visited[nx][ny] = 1;
                q.push(node(nx, ny, front.step + 1));
            }
        }
    }
}

int main() {
//    cout << maxn << endl;
    while (cin >> n >> m) {
        init();
        int y_x, y_y;
        int m_x, m_y;
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                char ch;
                scanf(" %c", &ch);
                if (ch == '#') {
                    origin_map[i][j] = 0;
                } else if (ch == '.') {
                    origin_map[i][j] = 1;
                } else if (ch == '@') {
                    origin_map[i][j] = 1;
                    kfc[kfc_num][0] = i;
                    kfc[kfc_num][1] = j;
                    kfc_num += 1;
                } else if (ch == 'Y') {
                    origin_map[i][j] = 1;
                    y_x = i;
                    y_y = j;
                } else if (ch == 'M') {
                    origin_map[i][j] = 1;
                    m_x = i;
                    m_y = j;
                }
            }
        }
        bfs(y_x, y_y, 'Y');
        bfs(m_x, m_y, 'M');
//        for (int i = 0; i < kfc_num; ++i) {
//            cout << y_distance[i] << " " << m_distance[i] << endl;
//        }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < kfc_num; i += 1) {
            ans = min(ans, y_distance[i] + m_distance[i]);
        }
        cout << ans * 11 << endl;
    }
    return 0;
}
/*
4 4
Y.#@
....
.#..
@..M
4 4
Y.#@
....
.#..
@#.M
5 5
Y..@.
.#...
.#...
@..M.
#...#
4 5
@.#@.
..Y#.
@#M#.
@..#@
*/