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
const int M = 100003;

int quick(int k)
{
    int ans = 1;
    int base = 2;
    while(k > 0){
        if(k & 1){
            ans *= base;
            ans %= M;
        }
        base *= base;
        base %= M;
        k>>=1;
    }
    return ans;
}


int main()
{
    int n,k;
    cin >> n;
    n--;
    k = 2;
    int f[n + 1];
    f[0] = 1;
    f[1] = 1;
    int tmp = 0;
    for(int i = 2;i <= k;i++){
        f[i] = 2*f[i - 1] % M;
    }
    for(int i = k + 1;i <= n;i++){
        f[i] = 2 * f[i - 1] - f[i - k - 1];
        f[i] =(f[i] + M) % M;
    }
    cout << f[n - 1] << endl;
    system("pause");
    return 0;
}