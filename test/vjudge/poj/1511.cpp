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
const double PI = acos(-1);
const int MAXN = 1e6+ 10;
int n,m,head[MAXN],cnt = 0;
struct Edge{
    int v,next;
    LL w;
}edge[MAXN];

void addedge(int u,int v,LL w){
    edge[++cnt].v = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

void init()
{
    memset(head,0,sizeof head);

}


int main()
{
    int T;
    cin >> T;
    while(T--){

    }
    //system("pause");
    return 0;
}

