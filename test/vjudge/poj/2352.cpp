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
const int MAXN = 32010;
int tree[MAXN],n,ans[MAXN];

inline int lowbit(int x)
{
    return x & -x;
}

void add(int x)
{
    while(x <= MAXN){
        tree[x] += 1;
        x += lowbit(x);
    }
}

int sum(int x)
{
    int sum = 0;
    while(x > 0){
        sum += tree[x];
        x -= lowbit(x);
    }
    return sum;
}


int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++){
        int x,y;
        scanf("%d%d",&x,&y);x++;
        ans[sum(x)]++;
        
        add(x);
        
    }
    for(int i = 0;i < n;i++){
        printf("%d\n",ans[i]);
    }
    //system("pause");
    return 0;
}