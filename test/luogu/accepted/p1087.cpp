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

struct node{
    char data;
    node *left,*right;
};


char fbi(string s)
{
    if(s.length() > 1){
        cout << fbi(s.substr(0,s.length() / 2));
        cout << fbi(s.substr(s.length() / 2,s.length() / 2));
    }
    if(s == string(s.length(),'0')) return 'B';
    if(s == string(s.length(),'1')) return 'I';
    return 'F';
}

int main()
{
    int n;string s;
    cin >> n >> s;
    cout << fbi(s) << endl;
    return 0;
}