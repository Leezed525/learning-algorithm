#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
//*(int(*)[10])arr_name
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MAXN = 50;
int pre[MAXN], in[MAXN];
struct node {
    int value;
    node *l, *r;
    node(int value = 0, node *l = NULL, node *r = NULL)
        : value(value), l(l), r(r){};
};

void buildtree(int l, int r, int &t, node *&root) {
    int flag = -1;
    for (int i = l; i <= r; i++) {
        if (in[i] == pre[t]) {
            flag = i;
            break;
        }
    }
    if (flag == -1) return;
    root = new node(in[flag]);
    t++;
    if (flag > l) buildtree(l, flag - 1, t, root->l);
    if (flag < r) buildtree(flag + 1, r, t, root->r);
}

void bfs(node *&root) {
    queue<node *> q;
    q.push(root);
    int cas = 0;
    while (!q.empty()) {
        node *tmp = q.front();
        if (cas) printf(" ");
        cas++;
        q.pop();
        printf("%d", tmp->value);
        if (tmp->r != NULL) q.push(tmp->r);
        if (tmp->l != NULL) q.push(tmp->l);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> in[i];
    for (int i = 1; i <= n; i++) cin >> pre[i];
    node *root;
    int t = 1;
    buildtree(1, n, t, root);
    bfs(root);
    // system("pause");
    return 0;
}