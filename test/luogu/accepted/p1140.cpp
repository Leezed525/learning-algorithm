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
int v[6][6]={   
            {0,0,0,0,0,0},
            {0,5,-1,-2,-1,-3},
            {0,-1,5,-3,-2,-4},
            {0,-2,-3,5,-2,-2},                {0,-1,-2,-2,5,-1},
            {0,-3,-4,-2,-1,0}
};
const int MAXN = 1e2 + 10;
int a[MAXN],b[MAXN];
int dp[MAXN][MAXN];

int turnnum(char x)
{
    if(x == 'A')
        return 1;
    else if(x == 'C')
        return 2;
    else if(x == 'G')
        return 3;
    else
        return 4;
}

int main()
{
    for(int i = 1;i < MAXN;i++){
        for(int j = 1;j < MAXN;j++){
            dp[i][j] = -INF;
        }
    }
    int n,m;
    string s1,s2;
    cin >> n >> s1 >> m >> s2;
    for(int i = 1;i <= n;i++){
        a[i] = turnnum(s1[i - 1]);
    }
    for(int i = 1;i <= m;i++){
        b[i] = turnnum(s2[i - 1]);
    }
    for(int i = 1;i <= n;i++){
        dp[i][0] = dp[i - 1][0] + v[a[i]][5];
    }
    for(int i = 1;i <= m;i++){
        dp[0][i] = dp[0][i - 1] + v[5][b[i]];
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            dp[i][j] = max(dp[i][j],dp[i - 1][j] + v[a[i]][5]);
            dp[i][j] = max(dp[i][j],dp[i][j - 1] + v[5][b[j]]);
            dp[i][j] = max(dp[i][j],dp[i - 1][j - 1] + v[a[i]][b[j]]);
        }
    }
    cout << dp[n][m] << endl;
    //system("pause");
    return 0;
}