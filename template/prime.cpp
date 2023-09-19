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

const int MAXN = 1e8 + 10;
bool isprime[MAXN];
int cnt = 0;
const int MAXM = 1e6 + 10;
int prime[MAXM];
void getprime(int n) {
    memset(isprime, 1, sizeof(isprime));
    for (int i = 2; i <= n; i++) {
        if (isprime[i]) {
            prime[++cnt] = i;
        }
        for (int j = 1; j <= cnt && i * prime[j] <= n; j++) {
            isprime[i * prime[j]] = 0;
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    getprime(n);
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        printf("%d\n", prime[x]);
    }
    // system("pause");
    return 0;
}