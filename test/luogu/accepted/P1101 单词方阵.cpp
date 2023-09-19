#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e2 + 5;
int n,u[8] = {0,-1,-1,-1,0,1,1,1},v[8] = {1,1,0,-1,-1,-1,0,1};
char mp[MAXN][MAXN];
bool ans[MAXN][MAXN];
char s[] = " yizhong";

bool dfs(int x,int y,int nn,int div)
{
	if(nn == 8){
		ans[x][y] = 1;
		return true;
		
	}
	int xx = x + u[div],yy = y + v[div];
	if(xx >= 1 && yy >= 1 && xx <= n && yy <= n && mp[xx][yy] == s[nn]){
		if(dfs(xx,yy,nn + 1,div)){
			ans[x][y] = 1;
			return true;
		}
	}
	return 0;
}
int main()
{
	cin >> n;
	getchar();
	getchar();
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			scanf("%c",&mp[i][j]);
		}
		getchar();
		getchar();
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(mp[i][j] == 'y'){
				for(int k = 0;k < 8;k++){
					if(dfs(i,j,2,k)){
						ans[i][j] = 1;
					}
				}
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(ans[i][j])
				cout << mp[i][j];
			else
				cout <<"*";
		}
		cout << endl;
	}
	
}
