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
const int MAXN = 5e4 + 10;
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

void un(int x,int y)
{
    int a = find_set(x);
    int b = find_set(y);
    if(a != b){
        f[a] = b;
    }
}

void init()
{
    for(int i = 1;i <= n;i++){
        f[i] = i;
    }
}


int main()
{
    cin >> n >> m;
    init();
    for(int i = 0;i < m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a == 2){
            int x = find_set(b);
            int y = find_set(c);
            if(x != y){
                printf("N\n");
            }
            else{
                printf("Y\n");
            }
        }
        else{
            un(b,c);
        }
    }
    //system("pause");
    return 0;
}