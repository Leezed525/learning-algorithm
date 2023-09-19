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
    n *= 2;
    for(int k1 = sqrt(n);k1 > 1;k1--){
        if(n % k1 == 0 && ((k1 % 2)^(n/k1 % 2))){
            int k2 = n / k1;
            cout << (k2-k1+ 1) / 2 << " " << (k1 + k2 - 1) / 2 << endl;
        }
    }
    system("pause");
    return 0;
}