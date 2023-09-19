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
const int MAXN = 2e5 + 5;
int a[MAXN];
int main()
{
    int n;
    cin >> n;
    int maxn = -INF;
    int tmp = 0;
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        tmp += a[i];
        maxn = max(maxn,tmp);
        if(tmp < 0){
            tmp = 0;
        }
        
    }
    cout << maxn << endl;
    return 0;
}