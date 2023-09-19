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

int main()
{
    int n,m;
    cin >> n >> m;
    queue<int>q;
    for(int i = 1;i <= n;i++)
        q.push(i);
    int num = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        num++;
        if(num == m){
            printf("%d%c",x,q.empty()?'\n':' ');
            num = 0;
        }
        else{
            q.push(x);
        }
    }
    return 0;
}