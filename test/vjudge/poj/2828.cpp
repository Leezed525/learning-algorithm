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
const int MAXN = 2e5 + 10;
int tree[MAXN];
int n,ans[MAXN];
struct node {
    int pos,val;
}id[MAXN];
inline int lowbit(int x){return x & -x;}

void add(int x)
{
    while(x <= n){
        tree[x] -= 1;
        x += lowbit(x);
    }
}

int sum(int x)
{
    int res = 0;
    while(x > 0){
        res += tree[x];
        x -= lowbit(x);
    }
    return res;
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

void init()
{
    for(int i = 1;i <= n;i++){
        tree[i] = lowbit(i);
    }
    memset(ans,0,sizeof(ans));
}

int main()
{
    while(cin >> n){
        init();
        for(int i = 1;i <= n;i++){
            scanf("%d%d",&id[i].pos,&id[i].val);
            id[i].pos++;
        }
        for(int i = n;i >= 1;i--){
            int x = findpos(id[i].pos);
            ans[x] = id[i].val;
            add(x);
        }
        for(int i = 1;i <= n;i++)
            printf("%d%c",ans[i],i == n?'\n':' ');
    }
    //system("pause");
    return 0;
}