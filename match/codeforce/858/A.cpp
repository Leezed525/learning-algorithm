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
    int n;
    cin >> n;
    while(n --) {
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if((x2 - x1) > (y2 - y1)){
            cout << -1 << endl;
        }else if(y1 > y2){
            cout << -1 << endl;
        }else{
            int num = y2 - y1;
            num += x1 + y2 - y1 - x2;
            cout << num << endl;
        }
    }   
    //system("pause");
    return 0;
}