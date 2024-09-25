//
// Created by Leezed on 2024/9/24.
//
#include "iostream"
#include "cstring"
#include "queue"

using namespace std;
const int maxn = 10;
int origin_map[maxn][maxn];
int visited[maxn][maxn];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int flag = 0;

queue<pair<int, int>> s;


void dfs(int x, int y) {

    if (x == 4 && y == 4) {
        flag = 1;
        while (!s.empty()) {
            pair<int, int> top = s.front();
            cout << "(" << top.first << ", " << top.second << ")" << endl;
            s.pop();
        }
        return;
    }

    for (int i = 0; i < 4; i += 1) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && origin_map[nx][ny] == 0 && visited[nx][ny] == 0) {
            visited[nx][ny] = 1;
            s.push(make_pair(nx, ny));
            dfs(nx, ny);
            if (flag == 1) {
                return;
            }
            visited[nx][ny] = 0;
            s.pop();
        }
    }
}


int main() {
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < 5; i += 1) {
        for (int j = 0; j < 5; j += 1) {
            cin >> origin_map[i][j];
        }
    }
    visited[0][0] = 1;
    s.push(make_pair(0, 0));
    dfs(0, 0);


    return 0;
}


