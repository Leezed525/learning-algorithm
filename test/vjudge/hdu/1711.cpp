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
const double PI = acos(-1);
const int MAXN =1e6 + 10;
const int MAXM = 1e4 + 10;
int n,m;
int s[MAXN],p[MAXM];
int ne[MAXM];

void getnext()
{
    int j;
    j = ne[0] = -1;
    int i = 0;
    while(i < m){
        while(j != -1 && p[i] != p[j])  j = ne[j];
        if(p[++i] == p[++j])
            ne[i] = ne[j];
        else
            ne[i] = j;
    }
}

int kmp()
{
    int i,j;
    i = j = 0;
    getnext();
    int res = -1;
    while(i < n){
        if(j == -1 || s[i] == p[j]){
            i++;
            j++;
        }
        else
            j = ne[j];
        if(j == m){
            return i - j + 1;
        }
    }
    return res;
    
}

int main()
{
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i = 0;i < n;i++)
            scanf("%d",&s[i]);
        for(int j = 0;j < m;j++)
            scanf("%d",&p[j]);
        cout << kmp() <<endl;
    }
    //system("pause");
    return 0;
}