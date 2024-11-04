//
// Created by Leezed on 2024/11/4.
//
#include "cstring"
#include "iostream"
#include "queue"
#include "set"

#define LL long long

using namespace std;

int a[4][8];
int pos[4][2];
LL ans_hash = 98430874871;
set<LL> vis;


struct node {
    int step;
    int status[4][8];
    int pos[4][2];

    node(int step, int status[4][8], int pos[4][2]) : step(step) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 8; ++j) {
                this->status[i][j] = status[i][j];
            }
        }
        for (int i = 0; i < 4; ++i) {
            this->pos[i][0] = pos[i][0];
            this->pos[i][1] = pos[i][1];
        }
    }
};


LL get_hash(int x[][8]) {
    LL key = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            key = key + x[i][j] * (1LL << (i * 8 + j));
        }
    }
    return key;
}


int bfs() {
    queue<node> q;
    node start = node(0, a, pos);
    vis.insert(get_hash(start.status));
    LL start_hash = get_hash(start.status);
    if (start_hash == ans_hash) {
        return 0;
    }
    q.push(start);
    while (!q.empty()) {
        node current = q.front();
        q.pop();
        for (int i = 0; i < 4; i += 1) {
            int x = current.pos[i][0];
            int y = current.pos[i][1]; //获取空格的位置 x,y
            int last_num = current.status[x][y - 1]; //获取空格前的数字
            if (last_num % 10 == 7 || last_num == 0) {
                continue;
            }
            int need_num = last_num + 1;
            bool find_flag = false;
            for (int j = 0; j < 4; j += 1) {
                for (int k = 1; k < 8; k += 1) {
                    if (current.status[j][k] == need_num) {
                        find_flag = true;
                        node next = node(current.step + 1, current.status, current.pos);
                        next.status[x][y] = need_num;
                        next.status[j][k] = 0;
                        next.pos[i][0] = j;
                        next.pos[i][1] = k;
                        LL next_hash = get_hash(next.status);
                        if (next_hash == ans_hash) {
                            return next.step;
                        }
                        if (vis.find(next_hash) == vis.end()) {
                            vis.insert(next_hash);
                            q.push(next);
                        }
                        break;
                    }
                }
                if (find_flag) {
                    break;
                }
            }
        }
    }
    return -1;
}

void init() {
    vis.clear();
}


int main() {
//    int ans[4][8] = {
//            {11, 12, 13, 14, 15, 16, 17, 0},
//            {21, 22, 23, 24, 25, 26, 27, 0},
//            {31, 32, 33, 34, 35, 36, 37, 0},
//            {41, 42, 43, 44, 45, 46, 47, 0}
//    };
//    cout << get_hash(ans) << endl;
    int T;
    cin >> T;
    while (T--) {
        init();
        int pos_count = 0;
        for (int i = 0; i < 4; i += 1) {
            for (int j = 1; j < 8; j += 1) {
                cin >> a[i][j];
                if (a[i][j] % 10 == 1) {
                    int tmp = a[i][j];
                    a[tmp / 10 - 1][0] = tmp;
                    a[i][j] = 0;
                    pos[pos_count][0] = i;
                    pos[pos_count++][1] = j;
                }
            }
        }
        cout << bfs() << endl;

//        for (int i = 0; i < 4; i += 1) {
//            for (int j = 0; j < 8; j += 1) {
//                cout << a[i][j] << " ";
//            }
//            cout << endl;
//        }
//
//        for (int i = 0; i < 4; i += 1) {
//            cout << pos[i][0] << " " << pos[i][1] << endl;
//        }
    }

    return 0;
}