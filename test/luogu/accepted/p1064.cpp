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
const int MAXN = 32010;
const int MAXM = 70;
int n,m;

struct node{
    int v,p,q;
}cs[MAXM],suicong[MAXM][MAXM],fenzu[MAXM][MAXM];
int cong[MAXM];
int f[MAXN],num[MAXM];

int main()
{
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        scanf("%d%d%d",&cs[i].v,&cs[i].p,&cs[i].q);
        cs[i].p *= cs[i].v;
        if(cs[i].q){
            cong[cs[i].q]++;
            suicong[cs[i].q][cong[cs[i].q]].v = cs[i].v;
            suicong[cs[i].q][cong[cs[i].q]].p = cs[i].p;
        }
    }
    for(int i = 1;i <= m;i++){
        if(cong[i]){
            memset(f,-1,sizeof(f));
            f[0] = 0;
            for(int j = 1;j <= cong[i];j++){
                for(int k = n - cs[i].v;k >= suicong[i][j].v;k--){
                    if(f[k] < f[k - suicong[i][j].v] + suicong[i][j].p && f[k - suicong[i][j].v] != -1){
                        f[k] = f[k - suicong[i][j].v] + suicong[i][j].p;
                    }
                }
            }
            for(int j = 0;j <= n - cs[i].v;j++){
                if(f[j] != -1){
                    num[i]++;
                    fenzu[i][num[i]].v = cs[i].v + j;
                    fenzu[i][num[i]].p = cs[i].p + f[j];
                }
            }
        }
        else if(!cs[i].q){
            num[i]++;
            fenzu[i][num[i]].v = cs[i].v;
            fenzu[i][num[i]].p = cs[i].p;
        }
        memset(f,0,sizeof(f));
        for(int i = 1;i <= m;i++){
            for(int j = n;j >= 0;j--){
                for(int k = 1;k <= num[i];k++){
                    if(j >= fenzu[i][k].v)
                        f[j] = max(f[j],f[j - fenzu[i][k].v] + fenzu[i][k].p);
                }
            }
        }
        
    }
    int ans = -INF; 
    for(int i = 0;i <= n;i++)
        ans = max(ans,f[i]);
    cout << f[n] << endl;
    system("pause");
    return 0;
}