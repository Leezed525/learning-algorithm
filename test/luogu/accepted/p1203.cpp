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
string s;
int n;

int getlength(int l)
{
    int r = l + 1;
    int len = 0;
    char a = s[l],b = s[r];
    while(l != r && (s[l] == a || s[l] == 'w')){
        l = (l + n - 1) % n;
        len++;
    }
    if(r == l){
        len++;
    }
    else
        l = (l + 1) % n;
    while(r != l && (s[r] == b || s[r] == 'w')){
        r = (r + n + 1) % n;
        len++;
    }
    return len;
}

int main()
{
    cin >> n >> s;
    int maxn = 0;
    int ans = -1;
    for(int i = 0;i < n - 1;i++){
        if(s[i] != s[i + 1]){
            if(s[i] == 'w'){
                s[i] = 'b';
                ans = max(ans,getlength(i));
                s[i] = 'r';
                ans = max(ans,getlength(i));
                s[i] = 'w';
            }
            ans = max(ans,getlength(i));
            
        }
    }
    if(ans == -1){
        printf("%d\n",n);
    }
    else{
        printf("%d\n",ans);
    }
    //system("pause");
    return 0;
}