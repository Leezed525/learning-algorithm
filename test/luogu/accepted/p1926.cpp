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
const int MAXN = 200;
int ti[MAXN],fenshu[MAXN],shijian[MAXN];
int n,m,k,r;
int dp1[MAXN];
int dp2[MAXN];
int main()
{
    cin >> n >> m >> k >> r;
    for(int i = 0;i < n;i++){
        scanf("%d",ti + i);
    }
    for(int i = 0;i < m;i++){
        scanf("%d",shijian + i);
    }
    for(int i = 0;i < m;i++){
        scanf("%d",&fenshu[i]);
    }
    int minn = INF;
    for(int i = 0;i < m;i++){
        for(int j = r;j >= shijian[i];j--){
            dp1[j] = max(dp1[j],dp1[j - shijian[i]] + fenshu[i]);
            if(dp1[j] >= k){
                minn = min(minn,j);
            }
        }
    }
    //cout << minn << endl;
    int maxn = 0;
    for(int i = 0;i < n;i++){
        for(int j = r - minn;j >= ti[i];j--){
            dp2[j] = max(dp2[j],dp2[j - ti[i]] + 1);
            maxn = max(maxn,dp2[j]);
        }
    }
    cout << maxn << endl;
    //system("pause");
    return 0;
}