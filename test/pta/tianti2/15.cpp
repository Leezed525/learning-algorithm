#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#include<sstream>
using namespace std;
//*(int(*)[10])arr_name
typedef long long LL;
const int INF = 0x3f3f3f3f;
using namespace std;
int n, c;
LL x[100000], y[100000];
int s[100000];
set<int> ans;
bool check(int a, int b, int c) {
    return (y[b] - y[a]) * (x[c] - x[a]) <= (y[c] - y[a]) * (x[b] - x[a]);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &x[i], &y[i]);
        if (c >= 1) {
            while (c >= 2 && check(i, s[c - 1], s[c - 2])) c--;
            if (s[c - 1]) ans.insert(s[c - 1]);
        }
        s[c++] = i;
    }
    printf("%d", ans.size());
}