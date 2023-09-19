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
const int MAXN = 1e5 + 5;
int d[MAXN];
int a[MAXN];
int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    int len = 0,ans = 0;
    for(int i = 0;i < n;i++){
        if(a[i] > d[len]){
            d[++len] = a[i];
        }
        else{
            *lower_bound(d+1,d + 1 + len,a[i]) = a[i];
            ans++;
        }
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}