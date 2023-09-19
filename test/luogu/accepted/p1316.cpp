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
int n,m;
const int MAXN = 1e5 + 5;
int a[MAXN];

bool check(int x){
    int tmp = a[1],num = 0;
    for(int i = 2;i <= n;i++){
        if(a[i] - tmp > x){
            num++;
            tmp = a[i];
        }
    }
    return num + 1 >= m;
}

int main()
{
    cin >> n >> m;
    int maxn = -INF;
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        maxn = max(maxn,a[i]);
    }
    sort(a+1,a+1+n);
    int l = 1,r = INF;
    while(l < r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            l = mid + 1;
        }
        else
            r = mid;
    }
    cout << l << endl;
    return 0;
}
