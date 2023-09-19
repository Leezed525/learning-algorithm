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
const int MAXN = 1e4 + 10;
int tree[MAXN],pre[MAXN],ans[MAXN];
int n;

int lowbit(int x){
    return x & -x;    
}
void add(int x,int d)
{
    while(x < n){
        tree[x] += d;
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

int findpos(int x)
{
    int l = 1,r = n;
    while(l < r){
        int mid = l + r >> 1;
        if(sum(mid) < x)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

int main()
{
    cin >> n;
    for(int i = 2;i <= n;i++)
        scanf("%d",&pre[i]);
    for(int i = 1;i <= n;i++){
        tree[i] = lowbit(i);
    }
    for(int i = n;i >= 1;i--){
        int x = findpos(pre[i] + 1);
        ans[i] = x;
        add(x,-1);
    }
    for(int i = 1;i <= n;i++)
        cout << ans[i] << endl;
    //system("pause");
    return 0;
}