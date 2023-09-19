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
const int MAXN = 10;
int iii = 0;
string start,goal;
map<string,int>mp;
string a[MAXN],b[MAXN];
struct node{
    string s;
    int step;
};

void bfs()
{
    node tmp;
    tmp.s = start;
    tmp.step = 0;
    mp[start] = 1;
    queue<node>q;
    q.push(tmp);
    while(!q.empty()){
        node tmp = q.front();
        q.pop();
        if(tmp.s == goal){
            printf("%d\n",tmp.step);
            return ;
        }
        if(tmp.step > 10)
            break;
        for(int i = 0;i < iii - 1;i++){
            string t = tmp.s;
            int m = 0;
            while(m != -1){
                m = t.find(a[i],m);
                if(m != -1){
                    string ss = t;
                    ss.replace(m,a[i].size(),b[i]);
                    node z;
                    z.s = ss;
                    z.step = tmp.step + 1;
                    if(mp[ss] == 0){
                        q.push(z);
                        mp[ss] = 1;
                    }
                    m++;
                }
            }
        }
    }
    printf("NO ANSWER!\n");
}

int main()
{
    cin >> start >> goal;
    while(cin >> a[iii] >> b[iii++]);
    bfs();
    return 0;
}