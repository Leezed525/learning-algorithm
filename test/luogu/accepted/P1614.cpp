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
#define ms(x, n) memset(x,n,sizeof(x));
using namespace std;
//*(int(*)[10])arr_name
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
inline int lowbit(int x) { return x & -x; }

int main()
{
    int n,m;
    cin >> n >> m;
    int num[n];
    for(int i = 0;i < n;i += 1){
        cin >> num[i];
    }
    int Min = 0;
    for(int  i = 0;i < m;i += 1){
        Min += num[i];
    }
    int last = Min;
    for(int i = m;i < n;i += 1){
        int x = last - num[i - m] + num[i];
        last = x;
        Min = min(Min, x);
    }
    cout << Min << endl;
    //system("pause");
    return 0;
}