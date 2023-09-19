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
const int MAXN = 1e2 + 10;
int tree[MAXN][MAXN],s[MAXN][MAXN],n,w,h;

int lowbit(int x)
{
    return x & -x;
}

void add(int x,int y)
{
    for(int i = x;i <= w;i += lowbit(i)){
        for(int j = y;j <= h;j += lowbit(j)){
            tree[i][j] += 1;
        }
    }
}

int sum(int x,int y)
{
    int res = 0;
    for(int i = x;i > 0;i -= lowbit(i)){
        for(int j = y;j > 0;j -=lowbit(j)){
            res += tree[i][j];
        }
    }
    return res;
}

int main()
{
    while(cin >> n && n){
        cin >> w >> h;
        memset(tree,0,sizeof(tree));
        for(int i = 0;i < n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            add(x,y);
        }
        for(int i = 1;i <= w;i++){
            for(int j = 1;j <= h;j++){
                s[i][j] = sum(i,j);
            }
        }
        // for(int i = 1;i <= w;i++){
        //     for(int j = 1;j <= h;j++){
        //         printf("%d ",s[i][j]);
        //     }
        //     cout <<endl;
        // }
        int x,y;
        scanf("%d%d",&x,&y);
        int maxn = -1,tmpx,tmpy;
        for(int i = 1;i + x <= w + 1;i++){
            for(int j = 1;j + y <= h + 1;j++){
                int tx = i + x - 1;
                int ty = j + y - 1;
                if(s[i - 1][j - 1] + s[tx][ty] - s[i - 1][ty] - s[tx][j - 1] > maxn){
                    maxn = s[i - 1][j - 1] + s[tx][ty] - s[i - 1][ty] - s[tx][j - 1];
                    tmpx = i;
                    tmpy = j;
                }
            }
        }
        //printf("%d %d\n",tmpx,tmpy);
        cout << maxn << endl;
    }
    //system("pause");
    return 0;
}
/*
16
10 8
2 2
2 5
2 7
3 3
3 8
4 2
4 5
4 8
6 4
6 7
7 5
7 8
8 1
8 4
9 6
10 3
4 3
8
6 4
1 2
2 1
2 4
3 4
4 2
5 3
6 1
6 2
3 2
0
*/