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
int n ;
bool valid(int x,int y) { 
    if(x <= 0 || y <= 0 || x > n || y > n) return false;
    return true;
}

int main() {
    int  m, k;
    cin >> n >> m >> k;
    int a[n + 1][n + 1];
    ms(a, 0);
    while (m--) {
        int x, y;
        cin >> x >> y;
        for(int i = x - 2;i <= x + 2;i += 1){
            if(valid(i,y)){
                a[i][y] = 1;
            }
        }
        for(int i = y - 2;i <= y + 2;i += 1){
            if(valid(x,i)){
                a[x][i] = 1;
            }
        }
        for(int i = x - 1;i <= x + 1;i += 1){
            for(int j = y-1;j <= y + 1;j += 1){
                if(valid(i,j)){
                    a[i][j] = 1;
                }
            }
        }
    }
    while(k--){
        int x,y;
        cin >> x >> y;
        for(int i = x - 2;i <= x + 2;i += 1){
            for(int j = y-2;j <= y + 2;j += 1){
                if(valid(i,j)){
                    a[i][j] = 1;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i += 1){
        for(int j = 1;j <= n;j += 1){
            if(a[i][j] == 0){
                ans += 1;
            }
        }
    }
    cout << ans << endl;
    // system("pause");
    return 0;
}