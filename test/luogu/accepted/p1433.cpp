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
int n;
const int MAXN = 20;
int biaoji[MAXN];
double mp[MAXN][MAXN];
struct node{
    double x,y;
}nailao[MAXN];
double minn = INF;
double path(node a,node b)
{
    double x = a.x - b.x;
    double y = a.y - b.y;
    return sqrt(x * x + y * y);
}

void dfs(int fa,double sum,int counts)
{   
    if(sum > minn)
        return ;
    if(counts == n){
        minn = min(sum,minn);
        return ;
    }
    for(int i = 1;i <= n;i++){
        if(!biaoji[i]){
            biaoji[i] = 1;
            dfs(i,sum+mp[fa][i],counts + 1);
            biaoji[i] = 0;
        }
    }
    return ;
}

int main()
{
    cin >> n;
    nailao[0].x = 0;
    nailao[0].y = 0;
    for(int i = 1;i <= n;i++){
        scanf("%lf%lf",&nailao[i].x,&nailao[i].y);
    }
    for(int i = 0;i<= n;i++){
        for(int j = 0;j<= n;j++){;
            mp[i][j] =  path(nailao[i],nailao[j]);
        }
    }
    dfs(0,0.0,0);
    printf("%.2lf\n",minn);
    return 0;
}