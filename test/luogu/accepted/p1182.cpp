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
int n,m;
int a[MAXN],maxn = -INF;
int sum = 0;

bool check(int x)
{
    int tmp = a[1];
    int num = 0;
    for(int i = 2;i <= n;i++){
        if(tmp + a[i] <= x){
            tmp += a[i];
        }
        else{
            tmp = a[i];
            num++;
        }
    }
    num++;
    if(num > m){
        return false;
    }
    return true;
}

int main()
{
    cin >> n >> m ;
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        sum += a[i];
        maxn = max(maxn,a[i]);
    }
    int l = maxn,r = sum;
    while(l < r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            r = mid;
        }
        else
            l = mid + 1;
    }
    cout << l << endl;
    return 0;
}