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
const int MAXN = 1010;
int s;
int prime[MAXN];
int dp[MAXN];
void dabiao()
{
    for(int i = 1;i <= s / 2;i++){
        for(int j = 2*i;j < s;j+=i){
            prime[j] += i;
        }
    }
    // for(int i = 1;i <= 10;i++){
    //     printf("%d ",prime[i]);
    // }
}
int main()
{
    cin >> s;
    dabiao();
    for(int i = 1;i <= s;i++){
        for(int j = s;j >= i;j--){
            dp[j] = max(dp[j],dp[j - i] + prime[i]);
        }
    }
    cout << dp[s] <<endl;
    //system("pause");
    return 0;
}