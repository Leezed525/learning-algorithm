#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
//*(int(*)[10])arr_name
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);

LL exgcd(LL a,LL b,LL &x,LL &y)//扩展欧几里得算法 
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    LL ret=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return ret;
}


LL getInv(int a,int mod)//求a在mod下的逆元，不存在逆元返回-1 
{
    LL x,y;
    LL d=exgcd(a,mod,x,y);
    return d==1?(x%mod+mod)%mod:-1;
}

int main() {
    cout << 35 * getInv(7, 4) % 4 << endl;
    cout << 35 % (7 * 4) / 7 << endl;
    // system("pause");
    return 0;
}