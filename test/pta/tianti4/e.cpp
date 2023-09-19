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

int main()
{
    int a,b;
    cin >> a >> b;
    printf("%d/",a);
    if(b < 0)
        printf("(%d)=",b);
    else
        printf("%d=",b);
    if(b == 0)
        printf("Error");
    else
    printf("%.2lf",a * 1.0 / b);
    //system("pause");
    return 0;
}