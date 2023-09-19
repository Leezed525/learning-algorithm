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
const double PI = acos(-1);
const int MAXN = 1e5 + 10;
struct node {
    int id;
    int k;
    node(int a, int b) {
        id = a;
        k = b;
    }
};
vector<node> v[MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int k;
        scanf("%d", &k);
        if (k == 1) {
            int num, a, b;
            scanf("%d%d%d", &num, &a, &b);
            v[num].push_back(node(a, b));
        }
        if (k == 2) {
            int num, a;
            scanf("%d%d", &num, &a);
            for (int j = v[num].size() - 1; j >= 0; j--) {
                if (v[num][j].id == a) {
                    printf("%d\n", v[num][j].k);
                    break;
                }
            }
        }
    }
    // system("pause");
    return 0;
}