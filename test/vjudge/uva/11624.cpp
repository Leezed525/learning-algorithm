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
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int vis1[MAXN], vis2[MAXN];
char mp[MAXN][MAXN];
int n, m;
struct node {
    int x, y;
    int step;
};

bool check(int x, int y) {
    if (x <= 0 || y <= 0 || x > n || y > m || mp[x][y] == '#') return false;
    return true;
}

void bfs() {
    
}

int main() {
    int T;
    cin >> T;
    while (T--) {
    }
    // system("pause");
    return 0;
}