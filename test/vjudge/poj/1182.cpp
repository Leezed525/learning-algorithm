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
#define ms(x, n) memset(x, n, sizeof(x));
using namespace std;
//*(int(*)[10])arr_name
typedef long long LL;
const int INF = 0x3f3f3f3f;
//const double PI = acos(-1);
const int MAXN = 1e5 + 10;
int n, m;
struct node {
    int pre;
    int relation;
} p[MAXN];

void init() {
    for (int i = 1; i <= n; i++) {
        p[i].pre = i;
        p[i].relation = 0;
    }
}

int getset(int x) {
    if (x == p[x].pre) return x;
    int fa;
    fa = p[x].pre;
    p[x].pre = getset(p[x].pre);
    p[x].relation = (p[x].relation + p[fa].relation) % 3;
    return p[x].pre;
}

int main() {
    cin >> n >> m;
    init();
    int sum = 0;
    for (int i = 1; i <= m; i++) {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if (x > n || y > n) {
            sum++;
            continue;
        }
        if (op == 2 && x == y) {
            sum++;
            continue;
        }
        int rootx = getset(x);
        int rooty = getset(y);
        if (rootx != rooty) {
            p[rooty].pre = rootx;
            p[rooty].relation = (3 + op - 1 + p[x].relation - p[y].relation) % 3;
        } else {
            if (op == 1 && p[x].relation != p[y].relation) {
                sum++;
                continue;
            } else if (op == 2 && op - 1 != (3 - p[x].relation + p[y].relation) % 3) {
                sum++;
                continue;
            }
        }
    }
    cout << sum << endl;
    // system("pause");
    return 0;
}