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
struct node {
    int id;
    int money;
    int num;
} p[10001];
int cmp(node p1, node p2) {
    if (p1.money > p2.money) {
        return 1;
    } else if (p1.money == p2.money) {
        if (p1.num > p2.num) {
            return 1;
        } else if (p1.num == p2.num) {
            if (p1.id < p2.id) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        p[i].id = i;
        p[i].money = 0;
        p[i].num = 0;
    }
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a, b;
            cin >> a >> b;
            p[a].num++;
            p[a].money += b;
            p[i].money -= b;
        }
    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        printf("%d %.2f\n", p[i].id, p[i].money * 1.0 / 100);
    }
}