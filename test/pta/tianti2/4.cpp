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
const int MAXN = 1e5 + 10;
int f[MAXN];
int vis[MAXN];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        for (int j = 1; j <= m; j++) {
            int id;
            scanf("%d", &id);
            if (m != 1) f[id] = 1;
        }
    }
    int flag = 1, cas = 0;
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int id;
        scanf("%d", &id);
        if (f[id] == 0) {
            if (cas) printf(" ");
            cas++;
            printf("%05d", id);
            f[id] = 1;
            flag = 0;
        }
    }
    if (flag) cout << "No one is handsome" << endl;
    // system("pause");
    return 0;
}