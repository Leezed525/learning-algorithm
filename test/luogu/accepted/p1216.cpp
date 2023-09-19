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
const int MAXN = 1e3 + 5;
LL a[MAXN][MAXN];
int n;


int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= i;j++){
            scanf("%lld",&a[i][j]);
        }
    }
    for(int i = n;i >= 1;i--){
        for(int j = 1;j <= i - 1;j++){
            a[i - 1][j] += max(a[i][j],a[i][j + 1]);
        }
    }
    cout << a[1][1] << endl;
    return 0;
}