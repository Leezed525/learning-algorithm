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
int yh[25];
int biaoji[20];
int n,allsum;
int ans[20],tmp[20],allflag = 0;

void dfs(int counts,int sum)
{
    if(counts == n && sum == allsum){
        for(int i = 0;i < n;i++){
            ans[i] = tmp[i];
        }
        allflag = 1;
        return ;
    }
    if(sum > allsum){
        return ;
    }
    for(int i = 1;i <= n;i++){
        if(!biaoji[i]){
            biaoji[i] = 1;
            tmp[counts] = i;
            dfs(counts + 1,sum + yh[counts] * i);
            if(allflag)
                return ;
            biaoji[i] = 0;
        }
    }
    return ;
}



int main()
{
    cin >> n >> allsum;
    yh[0] = yh[n - 1] = 1;
    for(int i = 1;i * 2 < n;i++){
        yh[i] = yh[n - 1 - i] = (n - i) * yh[i - 1] / i;
    }
    dfs(0,0);
    if(allflag){
        for(int i = 0;i < n;i++){
            printf("%d%c",ans[i],i == n - 1?'\n':' ');
        }
    }
    return 0;
}
