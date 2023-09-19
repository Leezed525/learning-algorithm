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

int main()
{
    int n;
    cin >> n;
    map<int,int>mp;
    for(int i = 1;i <= n;i++){
        int m;
        scanf("%d",&m);
        for(int i = 1;i <= m;i++){
            int x;
            scanf("%d",&x);
            mp[x]++;
        }
    }
    int maxn = 0,vis;
    for(auto it:mp){
        if(it.second > maxn){
            vis = it.first;
            maxn = it.second;
        }
        else if(it.second == maxn && it.first > vis){
            vis = it.first;
            maxn = it.second;
        }
    }
    cout << vis << " " << maxn << endl;
    //system("pause");
    return 0;
}