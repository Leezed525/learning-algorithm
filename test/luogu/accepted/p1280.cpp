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
const int MAXN = 1e4 + 5;
struct node{
    int st;
    int len;
}task[MAXN];
int len[MAXN];
int dp[MAXN];
bool cmp(node a,node b){
    return a.st > b.st;
}
int main()
{
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        scanf("%d%d",&task[i].st,&task[i].len);
        len[task[i].st]++;
    }
    sort(task,task + m,cmp);
    int num = 0;
    for(int i = n;i >= 1;i--){
        if(len[i] == 0){
            dp[i] = dp[i + 1] + 1;
        }
        else{
            for(int j = 0;j < len[i];j++,num++){
                dp[i] = max(dp[i],dp[i + task[num].len]);
            }
        }
    }
    cout << dp[1] << endl;
    system("pause");
    return 0;
}