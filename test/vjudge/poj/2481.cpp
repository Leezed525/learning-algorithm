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
const int MAXN = 151000;
int n,tree[MAXN],ans[MAXN];
struct node{
    int l,r;
    int id;
}cow[MAXN];

bool cmp(node a,node b)
{
    if(a.r == b.r)
        return a.l < b.l;
    return a.r > b.r;
}

int lowbit(int x)
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
    while(cin >> n && n){
        memset(tree,0,sizeof(tree));
        memset(ans,0,sizeof(ans));
        for(int i = 1;i <= n;i++){
            scanf("%d%d",&cow[i].l,&cow[i].r);
            cow[i].l++;cow[i].r++;
            cow[i].id = i;
        }
        sort(cow + 1,cow + n + 1,cmp);
        int flag = 0;
        for(int i = 1;i <= n;i++){
            if(cow[i].l == cow[i - 1].l && cow[i].r == cow[i - 1].r)flag++;
            else flag = 0;
            ans[cow[i].id] = sum(cow[i].l) - flag;
            add(cow[i].l);            
        }
        for(int i=1;i<=n;i++)printf("%d ",ans[i]);
        printf("\n");
    }
    //system("pause");
    return 0;
}
/*
4
0 3
0 3
1 2
3 4
3
1 2
0 3
3 4
*/