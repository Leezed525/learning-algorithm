//
// Created by Leezed on 2024/9/24.
//
#include "iostream"
#include "cstring"
#include "queue"

using namespace std;
const int maxn = 15;
int origin_map[maxn][maxn];
int visited[maxn][maxn];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

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

bool check(int x, int y, int n, int m) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return false;
    }
    return true;
}

void print_map(int n, int m) {
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            cout << origin_map[i][j] << " ";
        }
        cout << endl;
    }
}

void single_bfs(int x, int y, int n, int m) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = 1;
    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = front.first + dx[i];
            int ny = front.second + dy[i];
            if (check(nx, ny, n, m)) {
                if (origin_map[nx][ny] == 1 && visited[nx][ny] == 0) {
                    visited[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int get_unicom_block(int n, int m) {
    int ans = 0;
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            if (origin_map[i][j] == 1 && visited[i][j] == 0) {
                single_bfs(i, j, n, m);
                ans++;
            }
        }
    }
    return ans;
}

bool check_map_clear(int n, int m) {
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            if (origin_map[i][j] == 1 && visited[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

int double_bfs(int x1, int y1, int x2, int y2, int n, int m) {
    int max_step = 0;
    node start1(x1, y1, 0);
    node start2(x2, y2, 0);
    queue<node> q;
    q.push(start1);
    q.push(start2);
    visited[x1][y1] = 1;
    visited[x2][y2] = 1;
    while (!q.empty()) {
        node front = q.front();
        q.pop();
        max_step = max(max_step, front.step);
        for (int i = 0; i < 4; i += 1) {
            int nx = front.x + dx[i];
            int ny = front.y + dy[i];
            if (check(nx, ny, n, m)) {
                if (origin_map[nx][ny] == 1 && visited[nx][ny] == 0) {
                    visited[nx][ny] = 1;
                    q.push(node(nx, ny, front.step + 1));
                }
            }
        }
    }
    if (check_map_clear(n, m)) {
        return max_step;
    } else {
        return -1;
    }
}


int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t += 1) {
        memset(origin_map, 0, sizeof(origin_map));
        memset(visited, 0, sizeof(visited));
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; ++j) {
                char ch;
                scanf("%c", &ch);
                if (ch == '.')
                    origin_map[i][j] = 0;
                else if (ch == '#')
                    origin_map[i][j] = 1;
                else if (ch == '\n') {
                    j--;
                    continue;
                }
            }
        }
//        print_map(n, m);
        int unicom_block = get_unicom_block(n, m);
        if (unicom_block > 2) {
            cout << "Case " << t << ": " << -1 << endl;
        } else {
            int min_ans = 0x3f3f3f3f;
            for (int x1 = 0; x1 < n; x1 += 1) {
                for (int y1 = 0; y1 < m; y1 += 1) {
                    for (int x2 = 0; x2 < n; x2 += 1) {
                        for (int y2 = 0; y2 < m; y2 += 1) {
                            if (origin_map[x1][y1] == 0 || origin_map[x2][y2] == 0) {
                                continue;
                            }
                            memset(visited, 0, sizeof(visited));
                            int ans = double_bfs(x1, y1, x2, y2, n, m);
                            if (ans != -1) {
                                min_ans = min(min_ans, ans);
                            }
                        }
                    }
                }
            }
            cout << "Case " << t << ": " << min_ans << endl;
        }
    }
    return 0;
}
/*
4
3 3
.#.
###
.#.
3 3
.#.
#.#
.#.
3 3
...
#.#
...
3 3
###
..#
#.#
*/