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
    int count[10] = {0};
    int l,r;
    cin >> l >> r;
    for(int i = l;i <= r;i++){
        int num = i;
        while (num)
        {
            count[num % 10]+= 1;
            num /= 10;
        }
    }
    for(int i = 0;i < 10;i+= 1){
        printf("%d ",count[i]); 
    }

    //system("pause");
    return 0;
}