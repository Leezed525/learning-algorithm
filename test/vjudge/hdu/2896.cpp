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
int ne[510][210];
string a[510];
void getnext(int n, string p) {
    int plen = p.length();
    int j, i = 0;
    j = ne[n][0] = -1;
    while (i < plen) {
        while (j != -1 && p[i] != p[j]) j = ne[n][j];
        if (p[++i] == p[++j])
            ne[n][i] = ne[n][j];
        else
            ne[n][i] = j;
    }
}

bool kmp(int n, string s, string p) {
    int plen = p.length();
    int slen = s.length();
    int j, i;
    j = i = 0;
    while (i < slen) {
        if (j == -1 || s[i] == p[j]) {
            i++;
            j++;
        } else
            j = ne[n][j];
        if (j == plen) return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        getnext(i, a[i]);
    }
    int m;
    cin >> m;
    int num = 0;
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        queue<int> ans;
        for (int j = 1; j <= n; j++) {
            if (kmp(j, s, a[j])) ans.push(j);
        }
        if (!ans.empty()) {
            num++;
            printf("web %d:", i);
            while (!ans.empty()) {
                printf(" %d", ans.front());
                ans.pop();
            }
            printf("\n");
        }
    }
    printf("total: %d\n", num);
    // system("pause");
    return 0;
}