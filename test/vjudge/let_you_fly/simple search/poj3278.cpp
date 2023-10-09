//
// Created by Leezed on 2023/10/8.
//
#include<cstring>
#include<cstdio>
#include "iostream"
#include "queue"
using namespace std;
int n, K;
const int MAX_K = 1e5 + 10;
bool vis[MAX_K];


struct Node {
    int x, step;
    Node(int x, int step) : x(x), step(step) {}
};



int main() {
    cin >> n >> K;
    memset(vis, false, sizeof(vis));
    queue<Node> q;
    q.push(Node(n, 0));
    vis[n] = true;
    while (!q.empty()) {
        Node node = q.front();
        q.pop();
        if (node.x == K) {
            cout << node.step << endl;
            break;
        }
        if (node.x - 1 >= 0 && !vis[node.x - 1]) {
            q.push(Node(node.x - 1, node.step + 1));
            vis[node.x - 1] = true;
        }
        if (node.x + 1 < MAX_K && !vis[node.x + 1]) {
            q.push(Node(node.x + 1, node.step + 1));
            vis[node.x + 1] = true;
        }
        if (node.x * 2 < MAX_K && !vis[node.x * 2]) {
            q.push(Node(node.x * 2, node.step + 1));
            vis[node.x * 2] = true;
        }
    }


    return 0;
}