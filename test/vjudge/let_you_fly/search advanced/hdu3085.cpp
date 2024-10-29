#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#define mod 1000000007
#define eps 1e-6
#define ll long long
#define INF 0x3f3f3f3f
#define MEM(x,y) memset(x,y,sizeof(x))
#define Maxn 1000
using namespace std;
int T,n,m;
int step;//走了几轮
char mp[Maxn][Maxn];//原始地图
int dt[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};//四个方向
struct node
{
    int x,y;//坐标
};
node now,net;
node zz[2],mm,gg;//鬼 M G
queue<node>q[2];//分别表示队列M和G
queue<node>qt;//后面函数要用到，过渡
bool judge(node tmp)
{
    for(int i=0; i<2; i++)
    {
        if(abs(tmp.x-zz[i].x)+abs(tmp.y-zz[i].y)<=step*2||mp[tmp.x][tmp.y]=='X'||mp[tmp.x][tmp.y]=='\0')
            return false;
    }
    return true;
}
bool bfs(int pos,int steps,char start,char endd)//队列的编号 M或G可以走的步数 开始标志 结束标志
{
    qt=q[pos];//替代，后面要根据不同的steps进行走路
    for(int j=0; j<steps; j++)//这一轮走几步
    {
        while(!qt.empty())
        {
            now=qt.front();
            qt.pop();
            q[pos].pop();
            if(!judge(now))//不满足
                continue;
            for(int i=0; i<4; i++)//四个方向
            {
                net.x=now.x+dt[i][0];
                net.y=now.y+dt[i][1];
                if(!judge(net)||mp[net.x][net.y]==start)
                    continue;
                if(mp[net.x][net.y]==endd)//M找到G或G找到M
                    return true;
                mp[net.x][net.y]=start;//将走过的地方表示为开始标志，即M或G已经来过这
                q[pos].push(net);
            }
        }
        qt=q[pos];//都向外走了一步，重新初始化qt，再向外走一步
    }
    return false;
}
int solve()
{
    step=0;//初始化
    while(!q[0].empty())//初始化队列，清空
        q[0].pop();
    while(!q[1].empty())
        q[1].pop();
    while(!qt.empty())
        qt.pop();
    q[0].push(mm);//分别入队
    q[1].push(gg);
    while(!q[0].empty()&&!q[1].empty())
    {
        step++;//走了几轮
        if(bfs(0,3,'M','G')||bfs(1,1,'G','M'))
            return step;
    }
    return -1;
}
int main()
{
    scanf("%d",&T);//这里都要用scanf和printf，不然会超时
    while(T--)
    {
        scanf("%d%d",&n,&m);
        MEM(mp,'X');//把地图初始化为X
        for(int cnt=0,i=1; i<=n; i++)
        {

            scanf("%s",&mp[i][1]);//一行一行存地图
            for(int j=1; j<=m; j++)
            {
//                scanf("%c",&mp[i][j]);
//                cin>>mp[i][j];
                if(mp[i][j]=='M')
                {
                    mm.x=i;
                    mm.y=j;
                }
                if(mp[i][j]=='G')
                {
                    gg.x=i;
                    gg.y=j;
                }
                if(mp[i][j]=='Z')
                {
                    zz[cnt].x=i;
                    zz[cnt].y=j;
                    cnt++;
                }
            }
        }
        printf("%d\n",solve());
    }
}