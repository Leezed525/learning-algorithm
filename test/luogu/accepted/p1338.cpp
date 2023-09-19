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
const int MAXN = 5e4 + 10;
int a[MAXN];
int main()
{
    int n,m;
    cin >> n >> m;
    int head = 1;
    int tail = n;
    for(int i = 1;i <= n;i++){
        LL x = n - i;
        if(x * (x - 1) / 2 >= (LL)m){
            a[head++] = i;
        }
        else{
            a[tail--] = i;
            m -= (tail - head + 1);
        }
    }
    for(int i = 1;i <= n;i++){
        printf("%d%c",a[i],i == n?'\n':' ');
    }
    //system("pause");
    return 0;
}