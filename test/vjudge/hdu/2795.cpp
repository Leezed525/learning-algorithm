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
struct node{
    int l,r;
    int num;
}tree[MAXN * 4];
inline int lc(int p)
{
    return p << 1;
}
inline int rc(int p)
{
    return p << 1 | 1;
}
inline void push_up(int p)
{
    tree[p].num = max(tree[lc(p)].num,tree[rc(p)].num);
}

void buildtree(int p,int l,int r,int k)
{
    tree[p].l = l;
    tree[p].r = r;
    if(l == r){
        tree[p].num = k;
        return ;
    }
    int mid = l + r  >> 1;
    buildtree(lc(p),l,mid,k);
    buildtree(rc(p),mid + 1,r,k);
    push_up(p);
}

int quary(int p,int l,int r,int k)
{
    if(l == r){
        tree[p].num -=k;
        return l;
    }
    int res;
    int mid = l + r >> 1;
    if(tree[lc(p)].num >= k)    res = quary(lc(p),l,mid,k);
    else    res = quary(rc(p),mid + 1,r,k);
    push_up(p);
    return res;
}

int main()
{
    int h,w,n;
    while(cin >> h >> w >> n){
        if(h > n)
            h = n;
        buildtree(1,1,h,w);
        for(int i = 0;i < n;i++){
            int k;
            scanf("%d",&k);
            if(k <= tree[1].num)
                cout << quary(1,1,h,k) << endl;
            else
                cout << -1 << endl;
        }
    }
    //system("pause");
    return 0;
}