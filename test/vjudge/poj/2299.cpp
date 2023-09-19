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
const int MAXN = 5e5 + 10;
int tree[MAXN],n,a[MAXN],t[MAXN];

int lowbit(int x)
{
    return x & -x;
}

void add(int x)
{
    while(x <= n){
        tree[x] += 1;
        x += lowbit(x);
    }
    return ;
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
    while(cin >> n && n){
        memset(tree,0,sizeof(tree));
        for(int i = 1;i <= n;i++){
            scanf("%d",&a[i]);
            t[i] = a[i];
        }
        sort(t + 1,t + 1 + n);
        int cnt = unique(t + 1,t + 1 + n) - t - 1;
        LL ans = 0;
        for(int i = 1;i <= n;i++){
            a[i] = lower_bound(t + 1,t + 1 + n,a[i]) - t;
            add(a[i]);
            ans += i - sum(a[i]);
        }
        cout << ans << endl;
        // for(int i = 1;i <= n;i++)
        //     printf("%d ",a[i]);
    }
    //system("pause");
    return 0;
}