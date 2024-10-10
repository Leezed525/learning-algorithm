//
// Created by Leezed on 2024/10/10.
//
#include "iostream"
#include "cstring"

using namespace std;
const int maxn = 10;
string s[maxn];
char predict[maxn * maxn];
char gene[] = {'A', 'C', 'G', 'T'};
int deep;
int n;

struct node {
    int pos[maxn];

    node() {
        for (int i = 0; i < n; i += 1) {
            pos[i] = 0;
        }
    }

    node(const node &a) {
        for (int i = 0; i < n; i += 1) {
            pos[i] = a.pos[i];
        }

    }

    void clear() {
        memset(pos, 0, sizeof(pos));
    }

    int estimate() { //评估当前状态与最终状态的最小差距
        int ans = 0;
        for (int i = 0; i < n; i += 1) {
            ans = max(ans, abs((int) s[i].length() - pos[i]));
        }
        return ans;
    }
};

node current;


int dfs(int step) {
    node pre = node(current);
    if (step + current.estimate() > deep) {
        return 0;
    }
    if (current.estimate() == 0) {
//        cout << predict << endl;
        cout << deep << endl;
        return 1;
    }
    for (int i = 0; i < 4; i += 1) {
        predict[step] = gene[i];
        int flag = 0; //代表当前插入的字符是否有用
        for (int j = 0; j < n; j += 1) {
            if (predict[step] == s[j][current.pos[j]]) {
                current.pos[j] += 1;
                flag = 1;
            }
        }
        if (flag) {
            if (dfs(step + 1)) {
                return 1;
            }
            current = pre;
        }
    }
    return 0;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        deep = 0;
        for (int i = 0; i < n; i += 1) {
            cin >> s[i];
            deep = max(deep, (int) s[i].length());
        }

        while (true) {
            current.clear();
            if (dfs(0)) {
                break;
            }
            deep += 1;
        }
    }


    return 0;
}
/*
3
4
ACGT
ATGC
CGTT
CAGT
4
ACG
ATGCT
CGTTT
CAGTC
4
AAAAA
CCCCC
GGGGG
TTTTT
 */