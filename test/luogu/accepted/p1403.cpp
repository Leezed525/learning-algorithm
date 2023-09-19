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

int main()
{
    int n;
    cin >> n;
    int i;
    LL ans = 0;
    for(i = 1;i <= n;i++){
        ans += n / i;
    }
    cout << ans << endl;
    return 0;
}