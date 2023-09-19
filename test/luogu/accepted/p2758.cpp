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
const int MAXN = 2010;
char a[MAXN], b[MAXN];
int dp[MAXN][MAXN];
int main() {
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    int lena = strlen(a + 1);
    int lenb = strlen(b + 1);
    for (int i = 1; i <= lena; i++)
        dp[i][0] = i;
    for (int i = 1; i <= lenb; i++)
        dp[0][i] = i;
    for (int i = 1; i <= lena; i++)
        for (int j = 1; j <= lenb; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] =
                    min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        }
    cout << dp[lena][lenb] << endl;
    // system("pause");
    return 0;
}