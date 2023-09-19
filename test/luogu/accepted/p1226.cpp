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
LL bb,p,k;
LL quickm(LL a,LL b)
{
    LL base = a;
    LL ans = 1;
    while(b > 0){
        if(b & 1){
            ans *= base;
            ans %= k;
        }
        b >>= 1;
        base*=base;
        base %= k;
    }
    return ans;
}
int main()
{
    cin >> bb >> p >> k;
    LL ans = quickm(bb,p);
    printf("%lld^%lld mod %lld=%lld",bb,p,k,ans%k);
    return 0;
}