#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define maxnum 300
#define inf 0x3f3f3f3f
const int MAXN = 2e2 + 10;
using namespace std;
double mp[MAXN][MAXN];
int x[MAXN],y[MAXN];

int main()
{
    int n,cas = 1;
    while(cin >> n && n){
        for(int i  = 1;i <= n;i++){
            scanf("%d%d",&x[i],&y[i]);
        }
        for(int i = 1;i <= n;i++){
            for(int j = i+1;j <= n;j++){
                mp[i][j]=mp[j][i]=sqrt(double(x[i]-x[j])*(x[i]-x[j])+double(y[i]-y[j])*(y[i]-y[j]));
            }
        }
        // for(int i = 1;i <= n;i++){
        //     for(int j = 1;j <= n;j++){
        //         printf("%4d",mp[i][j]);
        //     }
        //     cout << endl;
        // }
        for(int k = 1;k <= n;k++){
            for(int i = 1;i <= n;i++){
                for(int j = 1;j <= n;j++){
                    mp[i][j] = min(mp[i][j],max(mp[i][k],mp[k][j]));
                }
            }
        }
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n",cas++,mp[1][2]);
    }
    //system("pause");
    return 0;
}