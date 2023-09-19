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
const int MAXN = 60;
struct node{
    int id;
    int xing;
    string name;
}na[MAXN],nv[MAXN],all[MAXN];
int vis[MAXN];
int main()
{
    int num0 = 0,num1=  0;
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        int xing;
        string name;
        cin >> xing >> name;
        all[i] = {i,xing,name};
        if(xing)
            na[++num1] = all[i];
        else
            nv[++num0] = all[i];
    }
    for(int i = 1;i <= n;i++){
        if(vis[i])
            continue;
        if(all[i].xing == 1){
            vis[all[i].id] = 1;
            vis[nv[num0].id] = 1;
            cout << all[i].name << " " << nv[num0--].name << endl;
        }
        else{
            vis[all[i].id] = 1;
            vis[na[num1].id] = 1;
            cout << all[i].name << " " << na[num1--].name << endl;
        }
    }
    //system("pause");
    return 0;
}