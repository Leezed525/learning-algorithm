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
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#define _USE_MATH_DEFINES
using namespace std;
//*(int(*)[10])arr_name
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MAXN = 35;
const int MAXM = 100;
LL a[MAXN];
int vis[MAXM];
int n, k;
bool pan(LL x) {
    int res = 0;
    while (x) {
        LL yu = x % k;
        if (yu > 1)
            return false;
        else if (yu == 1) {
            if (vis[res] == 1) {
                return false;
            } else
                vis[res] = 1;
        }
        x = x / k;
        res++;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {

        cin >> n >> k;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }
        int flag = 0;
        for (int i = 1; i <= n; i++) {
            int yu = 0;
            int res = 0;
            if (!pan(a[i])) {
                flag = 1;
                break;
            }
        }
        if (flag)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
        cout << M_PI << endl;
    }
    // system("pause");
    return 0;
}