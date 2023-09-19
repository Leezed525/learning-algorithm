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
#define ms(x, n) memset(x,n,sizeof(x));
using namespace std;
//*(int(*)[10])arr_name
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
const int MAXN = 2e6 + 10;
int id[MAXN];
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        scanf("%d",&id[i]);
    for(int i = 1;i <= m;i++){
        int x;
        scanf("%d",&x);
        printf("%d\n",id[x]);
    }
    //system("pause");
    return 0;
}