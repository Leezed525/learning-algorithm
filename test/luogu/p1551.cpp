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
const int MAXN = 5000 + 10;
int f[MAXN];
int n,m,p;

int findset(int x)
{
    return x == f[x]?x:f[x] = findset(f[x]);
}

void unionset(int a,int b)
{
    int x = findset(a);
    int y = findset(b);
    if(x != y){
        f[x] = y;
    }
}

void init()
{
    for(int i = 1;i <= n;i++)
        f[i] = i;
}
int main()
{
    cin >> n >> m >> p;
    init();
    for(int i = 1;i <= m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        unionset(a,b);
    }
    for(int i = 1;i <= p;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        int x = findset(a);
        int y = findset(b);
        if(x != y)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    //system("pause");
    return 0;
}