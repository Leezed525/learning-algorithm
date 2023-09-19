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

int pan(int x)
{
    int vis[10] = {0};
    int res = 0;
    if(x < 1000){
        res++;
        vis[0] = 1;
    }
    while(x > 0){
        int tmp  = x % 10;
        if(vis[tmp] == 0){
            res++;
            vis[tmp] = 1;
        }
        x /= 10;
    }
    return res;
}

int main()
{
    int n,k;
    cin >> n >> k;
    for(int i = n;i <= 5000;i++){
        if(pan(i) == k){
            printf("%d %04d\n",i - n,i);
            return 0;
        }
            
        
    }
    //system("pause");
    return 0;
}