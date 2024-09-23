//
// Created by Leezed on 2024/9/23.
//
#include <queue>
#include "iostream"
#include "cstring"

using namespace std;
int num[10000];

bool is_prime(int x) {
    if (x == 1) {
        return false;
    }
    for (int i = 2; i * i <= x; i += 1) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;

}

void get_prime() {
    for (int i = 0; i < 10000; i += 1) {
        if (is_prime(i)) {
//            printf("i = %d\n", i);
            num[i] = 1;
        }
    }
}

int get_ten_pow(int x) {
    int ans = 1;
    for (int i = 0; i < x; i += 1) {
        ans *= 10;
    }
    return ans;
}

struct node {
    int num;
    int step;

    node(int num, int step) {
        this->num = num;
        this->step = step;
    }
};

int main() {
    get_prime();
    int T;
    cin >> T;
    while (T--) {
        int start, end;
        cin >> start >> end;
        bool vis[10000];
        queue<node> q;
        q.push(node(start, 0));
        memset(vis, 0, sizeof(vis));
        vis[start] = true;
        int flag = -1;

        while (!q.empty()) {
            node now = q.front();
            q.pop();
            if (now.num == end) {
                cout << now.step << endl;
                flag = now.step;
                break;
            }
            for (int i = 0; i < 4; i += 1) {
                for (int j = 0; j < 10; j += 1) {
                    int tmp = now.num;
                    if (i == 3 && j == 0) {
                        continue;
                    }
                    tmp = tmp - (tmp / (int) get_ten_pow(i) % 10) * (int) get_ten_pow(i);
                    tmp += j * (int) get_ten_pow(i);
                    if (num[tmp] && !vis[tmp]) {
//                        printf("tmp = %d\n", tmp);
                        vis[tmp] = true;
                        q.push(node(tmp, now.step + 1));
                    }
                }
            }
        }
        if (flag == -1) {
            cout << "Impossible" << endl;
        }
    }
    return 0;
}

