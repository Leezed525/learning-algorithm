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
int n,a,b,len = 0;
const int MAXN = 210;
int biaoji[MAXN],ans = -1;
int f[MAXN];

struct node {
    int fl;
    int step;
    node(int a,int b){
        fl = a;
        step = b;
    }
};

bool check(int x)
{
    if(x <= 0 || x > n || biaoji[x] == 1){
        return false;
    }
    return true;
}

void bfs()
{
    queue<node>q;
    q.push(node(a,0));
    while(!q.empty()){
        node tmp = q.front();
        q.pop();
        biaoji[tmp.fl] = 1;
        if(tmp.fl == b){
            ans = tmp.step;
            return ;
        }
        int x = tmp.fl;
        if(check(x + f[x])){
            q.push(node(x + f[x],tmp.step + 1));
        }
        if(check(x - f[x])){
            q.push(node(x - f[x],tmp.step + 1));
        }
    }
    return ;
}

int main()
{
    cin >> n >> a >> b;
    for(int i = 1;i <= n;i++){
        scanf("%d",&f[i]);
    }
    bfs();
    cout << ans << endl;
    return 0;
}