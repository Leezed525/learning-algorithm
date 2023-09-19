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
    int n,a,last = 0;
    LL ans = 0;
    cin >> n;
    for(int i = 0;i < n;i++){
        scanf("%d",&a);
        if(a > last){
            ans += (a - last);
        }
        last = a;
    }
    cout << ans <<endl;
    //system("pause");
    return 0;
}