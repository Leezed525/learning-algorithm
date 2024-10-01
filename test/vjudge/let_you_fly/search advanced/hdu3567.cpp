//
// Created by Leezed on 2024/10/1.
//
#include "iostream"
#include "cstring"
#include "queue"

using namespace std;

typedef long long ll;

ll pow4[30];

const int jiec[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
char dirs[] = {'d', 'l', 'r', 'u'};
const int maxn = 362880 + 10;
int v[2][maxn];
ll path[2][maxn];
int min_ans = 0x3f3f3f3f;
string result;

struct node {
    int status[9];
    int cantor_hash;
    int loc; // 9的位置
    int step; //当前步数
    int flag; // 0正向 1反向
    ll path; // 当前路径
    node() {
        memset(status, 0, sizeof(status));
        cantor_hash = 0;
        loc = 0;
        step = 0;
        flag = 0;
        path = 0;
    }
};

int cantor(int a[]) {
    int res = 0;
    for (int i = 0; i < 9; i += 1) {
        int small = 0;
        for (int j = i + 1; j < 9; j += 1) {
            if (a[j] < a[i]) {
                small += 1;
            }
        }
        res += small * jiec[8 - i];
    }
    return res;
}

void get_pow4() {
    pow4[0] = 1;
    for (int i = 1; i < 30; i += 1) {
        pow4[i] = pow4[i - 1] * 4;
    }
}

void init() {
    memset(v, -1, sizeof(v));
    memset(path, 0, sizeof(path));
    min_ans = 0x3f3f3f3f;
    result = "";
}

bool check_pos_legal(int x, int y) {
    if (x < 0 || x >= 3 || y < 0 || y >= 3) {
        return false;
    }
    return true;
}

string get_str(ll path, int flag, int cantor_hash) {
    string res = "";
    int tmp[100];
    int count = 0;
    for (int i = 1; i <= v[flag][cantor_hash]; i++) {
        tmp[++count] = path % 4;
        path /= 4;
    }
    for (int i = count; i >= 1; i--) {
        res += dirs[tmp[i]];
    }
    return res;
}


void bfs(node ss, node ee) {
    init();
    queue<node> q;
    ss.cantor_hash = cantor(ss.status);
    ee.cantor_hash = cantor(ee.status);
    ss.step = 0;
    ee.step = 0;
    ss.flag = 0;
    ee.flag = 1;
    ss.path = 0;
    ee.path = 0;
    q.push(ss);
    q.push(ee);
    v[0][ss.cantor_hash] = 0;
    v[1][ee.cantor_hash] = 0;

    if (ss.cantor_hash == ee.cantor_hash) {
        cout << 0 << endl << endl;
        return;
    }

    while (!q.empty()) {
        node now = q.front();
        q.pop();
        int x = now.loc / 3;
        int y = now.loc % 3;
        for (int i = 0; i < 4; i += 1) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (check_pos_legal(nx, ny)) {
                node next = now;
                next.loc = nx * 3 + ny;
                swap(next.status[now.loc], next.status[next.loc]);
                next.cantor_hash = cantor(next.status);
                next.step = now.step + 1;
                //生成路径
                if (next.flag == 0) { //正向
                    next.path = now.path * 4 + i;
                } else { //反向
                    next.path = (3 - i) * pow4[now.step] + now.path;
                }

                if (v[next.flag][next.cantor_hash] == -1) { //同方向上没有访问过
                    v[next.flag][next.cantor_hash] = next.step;
                    path[next.flag][next.cantor_hash] = next.path;
                } else { //被访问过了
                    if (next.step > v[next.flag][next.cantor_hash]) {
                        continue;
                    }
                    if (path[now.flag][next.cantor_hash] > next.path) { //更新字典序
                        path[now.flag][next.cantor_hash] = next.path;
                    }else {
                        continue;
                    }
                }
                if (v[now.flag ^ 1][next.cantor_hash] != -1) { //另一个方向也访问到了这个点的情况
                    string s0 = get_str(path[0][next.cantor_hash], 0, next.cantor_hash);
                    string s1 = get_str(path[1][next.cantor_hash], 1, next.cantor_hash);
                    string s = s0 + s1;
                    int len = s.length();
                    if (len < min_ans) {
                        min_ans = len;
                        result = s;
                    } else if (len == min_ans) {
                        if (result.compare(s) > 0) {
                            result = s;
                        }
                    } else { //到这一步的时候就说明最先碰撞的状态已经访问过了
                        cout << min_ans << endl;
                        cout << result << endl;
                        return;
                    }
                }
                q.push(next);
            }
        }
    }

}


int main() {
    get_pow4();
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt += 1) {
        string START, END;
        cin >> START >> END;
        node ss, ee;
        for (int i = 0; i < 9; i += 1) {
            if (START[i] == 'X') {
                ss.status[i] = 9;
                ss.loc = i;
            } else {
                ss.status[i] = START[i] - '0';
            }
            if (END[i] == 'X') {
                ee.status[i] = 9;
                ee.loc = i;
            } else {
                ee.status[i] = END[i] - '0';
            }
        }
        cout << "Case " << tt << ": ";
        bfs(ss, ee);
    }
}
