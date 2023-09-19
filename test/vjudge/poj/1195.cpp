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
const int MAXN = 1040;
int tree[MAXN][MAXN],n,s;

int lowbit(int x)
{
    return x & -x;
}

void add(int x,int y,int d)
{
    for(int i = x;i <= s;i += lowbit(i)){
        for(int j = y;j <= s;j += lowbit(j)){
            tree[i][j] += d;
        }
    }
}

int sum(int x,int y)
{
    int sum = 0;
    for(int i = x;i > 0;i -= lowbit(i)){
        for(int j = y;j > 0;j -= lowbit(j)){
            sum += tree[i][j];
        }
    }
    return sum;
}

int main()
{
    while(cin >> n){
        if(n == 0){
            cin >> s;
            memset(tree,0,sizeof(tree));
        }
        else if(n == 1){
            int x,y,d;
            scanf("%d%d%d",&x,&y,&d);
            x++;y++;
            add(x,y,d);
        }
        else if(n == 2){
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            x1++;
            x2++;
            y1++;
            y2++;
            cout << sum(x2,y2) + sum(x1-1,y1-1) - sum(x1-1,y2) - sum(x2,y1-1) <<endl;
        }
        else if(n == 3)
            break;
    }
    //system("pause");
    return 0;
}