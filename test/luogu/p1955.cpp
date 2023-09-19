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
const int MAXN = 2e5 + 10;
int f[MAXN], n, length;
int book[MAXN];
struct node {
    int a, b, c;
} l[MAXN];

bool cmp(node a, node b) { return a.c > b.c; }

int getf(int x) { return x == f[x] ? x : f[x] = getf(f[x]); }

void init(int x) {
    for (int i = 0; i <= x; i++) f[i] = i;
}

int findnum(int x) { return lower_bound(book, book + length, x) - book; }

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int num = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d", &l[i].a, &l[i].b, &l[i].c);
            book[num++] = l[i].a;
            book[num++] = l[i].b;
        }
        sort(book, book + 2 * n);
        sort(l + 1, l + 1 + n, cmp);
        length = unique(book, book + 2 * n) - book;
        init(length);
        int flag = 0;
        for (int i = 1; i <= n; i++) {
            if (l[i].c == 1) {
                int x = getf(findnum(l[i].a));
                int y = getf(findnum(l[i].b));
                if (x != y) {
                    f[x] = y;
                }
            } else {
                int x = getf(findnum(l[i].a));
                int y = getf(findnum(l[i].b));
                if (x == y) {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    // system("pause");
    return 0;
}