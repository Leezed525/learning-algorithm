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
/**
 * kmp
 * 此模板返回s中第一个p的位置
 */
int ne[MAXN];

void getnext(string p) {
    int plen = p.length();
    int j = ne[0] = -1;
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
    int slen = s.length();
    int plen = p.length();
    int i, j;
    i = j = 0;
    getnext(p);
    int res = -1;
    while (i < slen) {
        if (j == -1 || s[i] == p[j]) {
            i++;
            j++;
        } else
            j = ne[j];
        if (j == plen) {
            res = i - plen;
            break;
        }
    }
    return res;
}

int main() {
    string s, p;
    while (cin >> s >> p) {
        cout << kmp(s, p) << endl;
    }
    // system("pause");
    return 0;
}