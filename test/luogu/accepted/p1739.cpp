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
    string s;
    cin >> s;
    stack<char>a;
    for(int i = 0;i < s.length();i++){
        if(s[i] == '('){
            a.push(s[i]);
        }
        else if(s[i] == ')'){
            if(a.empty() || a.top() != '('){
                printf("NO\n");
                return 0;
            }
            else{
                a.pop();
            }
        }
        
    }
    if(a.empty())
        printf("YES\n");
    else{
        printf("NO\n");
    }
    return 0;
}