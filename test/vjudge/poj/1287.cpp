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
const int MAXN = 60;
int n,m;
int mp[MAXN][MAXN];
int lowcost[MAXN],mst[MAXN];
int prim()
{
    int res = 0;
    for(int i = 1;i <= n;i++){
        lowcost[i] = mp[1][i];
        mst[i] = 1;
    }
    mst[1] = -1;
    for(int i = 1;i < n;i++){
        int minn = INF;
        int v = -1;
        for(int j = 1;j <= n;j++){
            if(mst[j] != -1 && lowcost[j] < minn){
                minn = lowcost[j];
                v = j;
            }
        }
        if(v != -1){
            res += minn;
            mst[v] = -1;
            for(int j = 1;j <= n;j++){
                if(mst[j] != -1 && lowcost[j] > mp[v][j]){
                    lowcost[j] = mp[v][j];
                    mst[j] = v;
                }
            }
        }
    }
    return res;
}


int main()
{
    while(cin >> n && n){
        cin >> m;
        memset(mp,INF,sizeof mp);
        memset(mst,0,sizeof mst);
        memset(lowcost,0,sizeof lowcost);
        for(int i = 0;i < m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            mp[u][v] = mp[v][u] = min(mp[u][v],w);
        }
        cout << prim() << endl;
    }    
    //system("pause");
    return 0;
}