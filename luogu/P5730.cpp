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

int getNum(char ch){
    return ch - '0';
}

int main()
{
    int image[10][5] ={
        7,5,5,5,7,
        1,1,1,1,1,
        7,1,7,4,7,
        7,1,7,1,7,
        5,5,7,1,1,
        7,4,7,1,7,
        7,4,7,5,7,
        7,1,1,1,1,
        7,5,7,5,7,
        7,5,7,1,7
    };
    int n ;
    cin >> n;
    string s;
    cin >> s;
    string ans[5];
    for(int i = 0;i < 5;i++){
        ans[i] = "";
    }
    for(int i = 0;i < n;i += 1){
        int num = getNum(s[i]);
        // cout << num << endl;
        for(int j = 0;j < 5;j += 1){
            int x = image[num][j];
            string tmps = "";
            while (x){
                if(x % 2==1){
                    tmps =  'X' + tmps;
                }else{
                    tmps =  '.' + tmps;
                }
                x /= 2;
            }
            int supplyLength = 3 - tmps.length();
            for(int k = 0;k < supplyLength;k += 1){
                tmps = '.' + tmps;
            }
            ans[j] += tmps;
            if(i != n - 1){
                ans[j] += '.';
            }
            
        }
    }
    for(int i = 0;i < 5;i += 1){
        cout << ans[i] << endl;
    }

    //system("pause");
    return 0;
}