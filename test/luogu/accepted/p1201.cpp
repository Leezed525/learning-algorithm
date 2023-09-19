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
map<string,int>mp1,mp2;
const int MAXN = 15;
string name[MAXN];
int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> name[i];
    }
    for(int i = 0;i < n;i++){
        string s;
        cin >> s;
        int a,b,sheng;
        cin >> a >> b;
        mp1[s] = a;
        if(b == 0){    
            continue;
        }
        sheng = a - a / b * b;
        mp2[s] += sheng;
        for(int j = 0;j < b;j++){
            string tmp;
            cin >> tmp;
            mp2[tmp] += a / b;
        }
    }
    for(int i = 0;i < n;i++){
        int a = mp2[name[i]];
        int b = mp1[name[i]];
        cout << name[i] << " " << a - b << endl; 
    }
    //system("pause");
    return 0;
}