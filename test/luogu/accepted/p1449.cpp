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
    string s1;
    cin >> s1;
    stack<int>s;
    int num1 = 0;
    for(int i = 0;i < s1.length();i++){
        if(s1[i] == '.'){
            s.push(num1);
            num1 = 0;
        }
        else if(s1[i] >= '0' && s1[i] <= '9'){
            num1 = num1 * 10 + s1[i] - '0';
        }
        else{
            int num = s.top();
            s.pop();
            if(s1[i] == '@'){
                cout << num << endl;
                break;
            }
            int x = s.top();
            s.pop();
            if(s1[i] == '-'){
                s.push(x - num);
            }
            else if(s1[i] == '+'){
                s.push(x + num);
            }
            else if(s1[i] == '*'){
                s.push(x * num);
            }
            else if(s1[i] == '/'){
                s.push(x / num);
            }
            num = 0;
        }
    }
    return 0;
}