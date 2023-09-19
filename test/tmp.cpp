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

bool isblank(char ch)
{
    if(ch == ' ' || ch == '\n')
        return true;
    return false;
}

string notblank(string s){
    string tmp = "";
    for(int i  = 0;i < s.length();i++){
        if(isblank(s[i]))
            continue;
        tmp += s[i];
    }
    return tmp;
}

int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    s1 = notblank(s1);
    s2 = notblank(s2);
    for(int i = 0;i < s1.length();i++){
        if(s1[i] != s2[i]){
            cout << s1[i] << endl;
            return 0;
        }
    }
    cout << "no" << endl;
    //system("pause");
    return 0;
}
