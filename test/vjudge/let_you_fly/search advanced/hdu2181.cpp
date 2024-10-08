//
// Created by Leezed on 2024/10/8.
//
#include "iostream"

using namespace std;

int mp[21][21];
bool visited[21];
int path[22];
int cnt = 1;
int m;

bool check() {
    for (int i = 1; i <= 20; i += 1) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}


void dfs(int start, int step) {
    if (start == m) {
        if (step != 1 && step <= 20) {
            return ;
        }
    }
    if (check()) {
        cout << cnt++ << ": ";
        for (int i = 1; i <= 21; i += 1) {
            cout << " " << path[i];
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= 20; i += 1) {
        if (mp[start][i] == 1 && !visited[i]) {
            visited[i] = true;
            path[step + 1] = i;
            dfs(i, step + 1);
            visited[i] = false;
        }
    }
}


int main() {

    for (int i = 1; i <= 20; i += 1) {
        int a, b, c;
        cin >> a >> b >> c;
        mp[i][a] = mp[i][b] = mp[i][c] = 1;
    }

    while (cin >> m && m != 0) {
        cnt = 1;
        path[1] = m;
        dfs(m, 1);
    }
    return 0;
}