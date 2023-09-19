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
const double PI = acos(-1);
const int MAXN = 40;
int tree[MAXN];
int flag = 0;
inline int lc(int p) { return p << 1; }
inline int rc(int p) { return p << 1 | 1; }
void build(int p, int num) {
    if (tree[p] == 0) {
        tree[p] = num;
        return;
    }
    if (num > tree[p]) build(lc(p), num);
    if (num < tree[p]) build(rc(p), num);
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        build(1, x);
    }
    bool flag = true;
    for (int cnt = 0, k = 1; cnt < n; k++) {
        if (tree[k] == 0)
            flag = false;
        else {
            if(cnt++)   printf(" ");
            printf("%d", tree[k]);
        }
    }
    if (flag) printf("\nYES");
    else    printf("\nNO");
    // system("pause");
    return 0;
}