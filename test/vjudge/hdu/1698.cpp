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
const int MAXN = 1e5 + 10;
struct node{
    int l,r;
    int sum,tag;
}tree[MAXN * 4];

inline int lc(int p)
{
    return p << 1;
}
inline int rc(int p)
{
    return p << 1 | 1;
}

void push_up(int p)
{
    tree[p].sum = tree[lc(p)].sum + tree[rc(p)].sum;
}
void buildtree(int p,int l,int r)
{
    tree[p].l = l;
    tree[p].r = r;
    tree[p].tag = -1;
    if(l == r){
        tree[p].sum = 1;
        return ;
    }
    int mid = l + r >> 1;
    buildtree(lc(p),l,mid);
    buildtree(rc(p),mid + 1,r);
    push_up(p);
}

inline void F(int p,int l,int r,int k)
{
    tree[p].sum = (r - l + 1) * k;
    tree[p].tag = k;
}

void push_down(int p,int l,int r)
{
    if(tree[p].tag == -1)
        return ;
    int mid =l + r >> 1;
    F(lc(p),l,mid,tree[p].tag);
    F(rc(p),mid + 1,r,tree[p].tag);
    tree[p].tag = -1;
}

void update(int nl,int nr,int l,int r,int p,int k)
{
    if(nl <= l && nr >= r){
        tree[p].sum = (r - l + 1) * k;
        tree[p].tag = k;
        return ;
    }
    push_down(p,l,r);
    int mid = l + r >> 1;
    if(nl <= mid)   update(nl,nr,l,mid,lc(p),k);
    if(nr > mid)    update(nl,nr,mid + 1,r,rc(p),k);
    push_up(p);
}

int main()
{
    int T,cas = 1;
    cin >> T;
    while(T--){
        int n,m;
        cin >> n >> m;
        buildtree(1,1,n);
        for(int i = 0;i < m;i++){
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            update(l,r,1,n,1,k);
        }
        printf("Case %d: The total value of the hook is %d.\n",cas++,tree[1].sum);
    }
    //system("pause");
    return 0;
}