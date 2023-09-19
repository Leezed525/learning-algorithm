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
const double PI = acos(-1);

bool isprime(int x)
{
    if(x == 1)
        return false;
    for(int i = 2;i <= sqrt(x);i++)
        if(x % i == 0)
            return false;
    return true;
}

int main()
{
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        if(isprime(n))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    //system("pause");
    return 0;
}