//
// Created by Leezed on 2023/10/4.
//
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>


using namespace std;
int L, R, C;
const int maxLRC = 30 + 5;
int mp[maxLRC][maxLRC][maxLRC];
int moved[maxLRC][maxLRC][maxLRC];
int min_ans = 0x3f3f3f3f;
int move_x[] = {0, 0, 0, 0, 1, -1};
int move_y[] = {0, 0, 1, -1, 0, 0};
int move_z[] = {1, -1, 0, 0, 0, 0};
int start_x, start_y, start_z;
int end_x, end_y, end_z;

void init() {
    memset(mp, 0, sizeof(mp));
    memset(moved, 0, sizeof(moved));
    min_ans = 0x3f3f3f3f;
}

void print_map() {
    for (int i = 0; i < L; i += 1) {
        for (int j = 0; j < R; j += 1) {
            for (int k = 0; k < C; k += 1) {
                cout << mp[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

bool check_pos_valid(int cur_x, int cur_y, int cur_z) {
    if (cur_x < 0 || cur_x >= L || cur_y < 0 || cur_y >= R || cur_z < 0 || cur_z >= C) {
        return false;
    }
    if (mp[cur_x][cur_y][cur_z] == 1) {
        return false;
    }
    if (moved[cur_x][cur_y][cur_z] == 1) {
        return false;
    }
    return true;
}
// dfs超时，改用bfs
//void dfs(int cur_x, int cur_y, int cur_z, int count) {
//    if (cur_x == end_x && cur_y == end_y && cur_z == end_z) {
//        min_ans = min(min_ans, count);
//        return;
//    }
//    for (int i = 0; i < 6; i += 1) {
//        int tmp_x = cur_x + move_x[i];
//        int tmp_y = cur_y + move_y[i];
//        int tmp_z = cur_z + move_z[i];
//        if (check_pos_valid(tmp_x, tmp_y, tmp_z)) {
//            moved[tmp_x][tmp_y][tmp_z] = 1;
//            dfs(tmp_x, tmp_y, tmp_z, count + 1);
//            moved[tmp_x][tmp_y][tmp_z] = 0;
//        }
//    }
//}

struct node {
    int x, y, z, count;
};

void bfs(){
    queue<node> q;
    node start = {start_x, start_y, start_z, 0};
    moved[start_x][start_y][start_z] = 1;
    q.push(start);
    while (!q.empty()) {
        node tmp = q.front();
        q.pop();
        if (tmp.x == end_x && tmp.y == end_y && tmp.z == end_z) {
            min_ans = min(min_ans, tmp.count);
            return;
        }
        for (int i = 0; i < 6; i += 1) {
            int tmp_x = tmp.x + move_x[i];
            int tmp_y = tmp.y + move_y[i];
            int tmp_z = tmp.z + move_z[i];
            if (check_pos_valid(tmp_x, tmp_y, tmp_z)) {
                moved[tmp_x][tmp_y][tmp_z] = 1;
                node next = {tmp_x, tmp_y, tmp_z, tmp.count + 1};
                q.push(next);
            }
        }
    }
}

int main() {
    while (cin >> L >> R >> C) {
        if (L == 0 && R == 0 && C == 0) {
            break;
        }
        init();
        for (int i = 0; i < L; i += 1) {
            for (int j = 0; j < R; j += 1) {
                for (int k = 0; k < C; k += 1) {
                    char tmp;
                    scanf("%c", &tmp);
                    if (tmp == 'S') {
                        start_x = i;
                        start_y = j;
                        start_z = k;
                    } else if (tmp == 'E') {
                        end_x = i;
                        end_y = j;
                        end_z = k;
                    } else if (tmp == '#') {
                        mp[i][j][k] = 1;
                    }
                    if (tmp == '\n') {
                        k -= 1;
                    }
                }
            }
        }
        bfs();
        if (min_ans != 0x3f3f3f3f) {
            cout << "Escaped in " << min_ans << " minute(s)." << endl;
        } else {
            cout << "Trapped!" << endl;
        }
//        print_map();
    }
    return 0;
}
