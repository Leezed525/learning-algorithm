//
// Created by Leezed on 2024/9/24.
//
#include "iostream"
#include "cstring"
#include "queue"

using namespace std;
const int maxn = 105;
int origin_map[maxn][maxn];
int visited[maxn][maxn];
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, 1, 1, -1, -1};

int n, m;

bool check(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return false;
    }
    return true;
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    visited[x][y] = 1;
    q.push(make_pair(x, y));
    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int nx = front.first + dx[i];
            int ny = front.second + dy[i];
            if (check(nx, ny)) {
                if (origin_map[nx][ny] == 1 && visited[nx][ny] == 0) {
                    visited[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}


int main() {

    while (cin >> n >> m && n != 0 && m != 0) {
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                char ch;
                scanf(" %c", &ch);
                if (ch == '*') {
                    origin_map[i][j] = 0;
                } else {
                    origin_map[i][j] = 1;
                }
            }
        }
        memset(visited, 0, sizeof(visited));
        int count = 0;
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                if (origin_map[i][j] == 1 && visited[i][j] == 0) {
                    count += 1;
                    bfs(i, j);
                }
            }
        }
        cout << count << endl;
//        for (int i = 0; i < n; i += 1) {
//            for (int j = 0; j < m; j += 1) {
//                printf("%d ", origin_map[i][j]);
//            }
//            cout << endl;
//        }
    }
    return 0;
}