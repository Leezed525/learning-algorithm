#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100;
int biaoji[MAXN];
int mp[MAXN][MAXN];
int path[MAXN];
int c = 0;
int n,m;
void dfs(int x)
{
	for(int i = 1;i <= n;i++){
		if(mp[x][i] == 1){
			mp[x][i] = mp[i][x] = 0;
			dfs(i);
			//biaoji[i] = 0;
		}
	}
	cout << x << " ";
}
int main()
{
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		mp[a][b] = 1;
		mp[b][a] = 1;
		mp[a][0]++;
		mp[b][0]++;
	}
	int flag = 1;
	for(int i = 1;i <= n;i++){
		if(mp[i][0] %2 == 1){
			flag = i;
			break;
		}
	}
	dfs(flag);
//	for(int i = 0;i < c;i++){
//		cout << path[i] << " ";
//	}
	return 0;
} 
