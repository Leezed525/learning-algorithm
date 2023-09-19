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

LL biao[16][10];

void dabiao()
{
    for(int i = 1;i <= 15;i++){
        biao[i][0] = 1;
        for(int j = 1;j < 10;j++){
            biao[i][j] = biao[i][j - 1] * i;
        }
    }
}


int main()
{
    dabiao();
    int k,n;
    cin >> k >> n;
    queue<int>s;
    while(n){
        s.push(n & 1);
        n >>= 1;
    }
    LL base = 1,ans = 0;
    while(!s.empty()){
        ans += s.front() * base;
        base *= k;
        s.pop();
    }
    cout << ans <<endl;
    //cout << ans << " " << maxnum <<endl;
    //system("pause");
    return 0;
}