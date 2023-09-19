#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10;
int dir[4][3]={{1,0},{0,1},{0,-1},{-1,0}};
int m,n,t,sx,sy,ex,ey,ans = 0;
int mp[MAXN][MAXN];

void dfs(int x,int y)
{
	if(x == ex && ey == y){
		ans++;
		return ;
	}
	for(int i = 0;i < 4;i++){
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if(xx >= 1 && yy >= 1 && xx <= n && y <= m && mp[xx][yy] == 0){
			mp[xx][yy] = 1;
			dfs(xx,yy);
			mp[xx][yy] = 0;
		}
	}
}
int main()
{
	cin >> n >> m >> t;
	cin >> sx >> sy >> ex >> ey;
	for(int i = 0;i < t;i++){
		int x,y;
		cin >> x >> y;
		mp[x][y] = 1;
	}
	mp[sx][sy] = 1;
	dfs(sx,sy);
	cout << ans << endl;
}
