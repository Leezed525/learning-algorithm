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
int num = 0;
const int MAXN = 1e3 + 5;
LL prime[MAXN];
bool is_prime(int x)
{
    for(int i = 2;i * i <= x;i++){
        if(x % i == 0)
            return false;
    }
    return true;
}
void dabiao()
{
    prime[0] = 1;
    for(int i = 2;i <= MAXN;i++){
        if(is_prime(i)){
            for(int j = i;j <= MAXN;j++){
                prime[j] += prime[j - i];
            }
        }
    }
}
int main()
{
    dabiao();
    int n;
    cin >> n;
    cout << prime[n] << endl;
    //system("pause");
    return 0;
}