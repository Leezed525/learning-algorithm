#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#define ms(x, n) memset(x, n, sizeof(x));
using namespace std;
//*(int(*)[10])arr_name
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
inline int lowbit(int x) { return x & -x; }

int main() {
    int m;
    cin >> m;
    while (m--) {
        int count;
        cin >> count;
        int step = 1;
        int flag = 0;
        int a[count + 1];
        for(int i = 1;i <= count ;i+=1){
            scanf("%d",&a[i]);
        }
        int min = 1000000;
        for(int i = 1;i <= count ;i+=1){
            for(int j = i;j <= count ;j+=1){
                int tmp = __gcd(a[i],a[j]);
                if(tmp < min){
                    min = tmp;
                }
            }
        }
        if(min <= 2){
            flag = 1;
        }
        if (flag) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    // system("pause");
    return 0;
}