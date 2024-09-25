//
// Created by Leezed on 2024/9/25.
//
#include "iostream"
#include "cstring"
#include "queue"

using namespace std;

const int maxn = 1e2 + 5;
int s, n, m;
int visited[maxn][maxn][maxn];

struct node {
    int s, n, m;
    int step;

    node(int s, int n, int m, int step) : s(s), n(n), m(m), step(step) {}
};

int bfs() {
    queue<node> q;
    q.push(node(s, 0, 0, 0));
    visited[s][0][0] = 1;
    while (!q.empty()) {
        node front = q.front();
        q.pop();
        if (front.s == front.m && front.n == 0 || front.s == front.n && front.m == 0 ||
            front.n == front.m && front.s == 0) {
//            cout << front.s << " " << front.n << " " << front.m << endl;
            return front.step;
        }
        if (front.s != 0) {
            if (front.n != n) {
                int pour = min(front.s, n - front.n);
                if (!visited[front.s - pour][front.n + pour][front.m]) {
                    visited[front.s - pour][front.n + pour][front.m] = 1;
                    q.push(node(front.s - pour, front.n + pour, front.m, front.step + 1));
                }
            }
            if (front.m != m) {
                int pour = min(front.s, m - front.m);
                if (!visited[front.s - pour][front.n][front.m + pour]) {
                    visited[front.s - pour][front.n][front.m + pour] = 1;
                    q.push(node(front.s - pour, front.n, front.m + pour, front.step + 1));
                }
            }
        }
        if (front.n != 0) {
            if (front.s != s) {
                int pour = min(front.n, s - front.s);
                if (!visited[front.s + pour][front.n - pour][front.m]) {
                    visited[front.s + pour][front.n - pour][front.m] = 1;
                    q.push(node(front.s + pour, front.n - pour, front.m, front.step + 1));
                }
            }
            if (front.m != m) {
                int pour = min(front.n, m - front.m);
                if (!visited[front.s][front.n - pour][front.m + pour]) {
                    visited[front.s][front.n - pour][front.m + pour] = 1;
                    q.push(node(front.s, front.n - pour, front.m + pour, front.step + 1));
                }
            }
        }
        if (front.m != 0) {
            if (front.s != s) {
                int pour = min(front.m, s - front.s);
                if (!visited[front.s + pour][front.n][front.m - pour]) {
                    visited[front.s + pour][front.n][front.m - pour] = 1;
                    q.push(node(front.s + pour, front.n, front.m - pour, front.step + 1));
                }
            }
            if (front.n != n) {
                int pour = min(front.m, n - front.n);
                if (!visited[front.s][front.n + pour][front.m - pour]) {
                    visited[front.s][front.n + pour][front.m - pour] = 1;
                    q.push(node(front.s, front.n + pour, front.m - pour, front.step + 1));
                }
            }
        }
    }
    return -1;
}

int main() {
    while (cin >> s >> n >> m && s != 0 && n != 0 && m != 0) {
        memset(visited, 0, sizeof(visited));
        int ans = bfs();
        if (ans == -1) {
            cout << "NO" << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;

}