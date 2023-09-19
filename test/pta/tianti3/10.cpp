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
const int MAXN = 1e5+ 10;
int t[MAXN];
int main()
{
    int n;
    cin >> n;
    int len = 0;
    for(int i = 1;i <= n;i++){
        int x;
        scanf("%d",&x);
        if(x > t[len])
            t[++len] = x;
        else{
            *lower_bound(t + 1,t + 1 + len,x) = x;
        }
    }
    cout << len <<endl;
    //system("pause");
    return 0;
}