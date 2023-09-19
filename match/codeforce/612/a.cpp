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
#define look(type,num,name) *(#type(*)[num])#name
typedef long long LL;
const int INF = 0x3f3f3f3f;

int main()
{
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int num = 0,maxn = -INF,flag = 0;
        for(int i = 0;i < n;i++){
            if(!flag){
                if(s[i] == 'A'){
                    flag = 1;
                }
            }
            else{
                if(s[i] == 'P'){
                    num++;
                }
                else{
                    maxn = max(maxn,num);
                    num = 0;
                }
            }
        }
        maxn = max(maxn,num);
        cout << max(maxn,0) << endl;
    }
    //system("pause");
    return 0;
}