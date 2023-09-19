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

LL gcd(LL a,LL b)
{
    return b == 0?a:gcd(b,a%b);
}

int main()
{
    LL a,b;
    cin >> a >> b;
    LL tmp = a * b;
    LL ans = 0;
    for(LL i = a; i * i < tmp;i++){
        if(tmp % i == 0 && gcd(i,tmp/i) == a){
            ans+=2;
        } 
    }
    cout << ans << endl;
    return 0;
}