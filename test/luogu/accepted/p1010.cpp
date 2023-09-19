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
stack<char>ans;

void output()
{
    while(!ans.empty()){
        printf("%c",ans.top());
        ans.pop();
    }
}

void dfs(int n)
{
    if(n == 0){
        //ans.push(')');
        ans.push('0');
        //ans.push('(');
        //ans.push('2');
        return ;
    }
    else if(n == 2){
        ans.push('2');
        return ;
    }
    else{
        int flag = 0;
        int x = 0;
        while(n > 0){
            if(n & 1){
                if(flag){
                    ans.push('+');
                }
                flag = 1;
                if(x == 1){
                    ans.push('2');
                }
                else{
                    ans.push(')');
                    dfs(x);
                    ans.push('(');
                    ans.push('2');
                }
                
            }
            n >>=1;
            x++;
        }
    }
    return ;
}

int main()
{
    int n;
    cin >> n;
    dfs(n);
    output();
    return 0;
}