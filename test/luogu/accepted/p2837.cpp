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
const int MAXN = 3e4 + 5;
int a[MAXN];
struct left{
    int one;
    int two;
};
struct right{
    int one;
    int two;
};
struct node{
    struct left l;
    struct right r;
};
node f[MAXN];
int n;
int main()
{
    cin >> n;
    f[0].l.one = 0;
    f[0].l.two = 0;
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        f[i].l = f[i - 1].l;
        if(a[i] == 1){
            f[i].l.one++;
        }
        else{
            f[i].l.two++;
        }
    }
    f[n].r.two = 0;
    f[n].r.one = 0;
    for(int i = n - 1;i >= 0;i--){
        f[i].r = f[i + 1].r;
        if(a[i + 1] == 1)
            f[i].r.one++;
        else
            f[i].r.two++;
    }
    int ans = INF;
    for(int i = 0;i <= n;i++){
        ans = min(ans,f[i].l.two + f[i].r.one);
    }
    ans = min(ans,f[0].r.two);
    cout << ans << endl;
    //system("pause");
    return 0;
}