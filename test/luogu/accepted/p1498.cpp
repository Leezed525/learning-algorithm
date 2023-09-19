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

const int MAXN = 2 * 1e3 ;
char mp[MAXN][MAXN];
int main()
{
    int n,i = 0;
    cin >> n;
    for(int i = 0;i < MAXN;i++){
        for(int j = 0;j < MAXN;j++){
            mp[i][j] = ' ';
        }
    }
    mp[0][0] = '/';mp[0][1] = '_';mp[0][2] = '_';mp[0][3] = '\\';
    mp[1][1] = '/';mp[1][2] = '\\';
    int tmp = 1;
    while(tmp < n){
        int x = pow(2,tmp + 1);
        int y = pow(2,tmp);
        for(int i = 0;i < y;i++){
            for(int j = 0;j < x;j++){
                mp[i][j + x] = mp[i][j];
                mp[i + y][j + y] = mp[i][j];
            }
        }
        tmp++;
    }
    int x = pow(2,n);
    for(int i = x - 1;i >= 0;i--){
        for(int j = 0;j < 2 * x - i;j++){
            printf("%c",mp[i][j]);
        }
        printf("\n");
    }
    return 0;
}