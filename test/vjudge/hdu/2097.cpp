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
const int MAXN = 1e3 + 10;
int Next[MAXN];

void getnext(string p) {
    int len = p.length();
    int j = Next[0] = -1;
    int i = 0;
    while (i < len - 1) {
        while (j != -1 && p[i] != p[j]) j = Next[j];
        if (p[++i] == p[++j])
            Next[i] = Next[j];
        else
            Next[i] = j;
    }
}

int kmp(string s, string p) {
    int slen = s.length();
    int plen = p.length();
    int res = 0;
    int j = 0, i = 0;
    while (i < slen) {
        if (j == -1 || s[i] == p[j]) {
            i++;
            j++;
        } else
            j = Next[j];
        if (j == plen) {
            j = 0;
            res++;
        }
    }
    return res;
}

int main() {
    string s, p;
    while (cin >> s && s != "#") {
        cin >> p;
        memset(Next, 0, sizeof(Next));
        getnext(p);
        cout << kmp(s, p) << endl;
    }
    // system("pause");
    return 0;
}