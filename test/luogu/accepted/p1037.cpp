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
int n,m;
const int MAXM = 2e5 + 10;
const int MAXN = 5e3 + 10;
int f[MAXN];
struct ed{
    int u,v,w;
}edge[MAXM];

bool cmp(ed a,ed b)
{
    return a.w < b.w;
}

int find_set(int x)
{
    return x == f[x]?x:f[x] = find_set(f[x]);
}

bool un(int x,int y)
{
    int a = find_set(x);
    int b = find_set(y);
    if(a != b){
        f[a] = b;
        return true;
    }
    return false;
}

void init()
{
    for(int i = 1;i <= n;i++){
        f[i] = i;
    }
}

void krusal()
{
    int ans = 0;
    for(int i = 0;i < m;i++){
        if(un(edge[i].u,edge[i].v)){
            ans += edge[i].w;
        }
    }
    int tmp = find_set(1);
    for(int i = 2;i <= n;i++){
        if(find_set(i) != tmp){
            printf("orz\n");
            return ;
        }
    }
    printf("%d\n",ans);

}

int main()
{
    cin >> n >> m;
    init();
    for(int i = 0;i < m;i++){
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
    }
    sort(edge,edge + m,cmp);
    krusal();
    //system("pause");
    return 0;
}