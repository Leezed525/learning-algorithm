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
const int MAXN = 1e4 + 10;
char s[1000100], p[MAXN];
int ne[MAXN];

void getnext(string p) {
    int plen = p.length();
    int j;
    j = ne[0] = -1;
    int i = 0;
    while (i < plen) {
        while (j != -1 && p[i] != p[j]) j = ne[j];
        if (p[++i] == p[++j])
            ne[i] = ne[j];
        else
            ne[i] = j;
    }
}

int kmp(string s, string p) {
    int plen = p.length();
    int slen = s.length();
    getnext(p);
    int i, j;
    i = j = 0;
    int res = 0;
    while (i < slen) {
        if (j == -1 || s[i] == p[j]) {
            i++;
            j++;
        } else
            j = ne[j];
        if (j == plen) {
            res++;
            j = ne[j];
        }
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        scanf("%s%s", p, s);
        printf("%d\n", kmp(s, p));
    }
    // system("pause");
    return 0;
}