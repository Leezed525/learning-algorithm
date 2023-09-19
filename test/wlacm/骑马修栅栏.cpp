#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5 * 1e2 + 5; 
int mp[MAXN][MAXN];
int n = 0;
int minnum = 0x3f3f3f3f;
void dfs(int x){
	cout << x << endl;
	for(int i = 1;i <= 500;i++){
		if(mp[i][x] == 1){
			mp[i][x] = mp[x][i] = 0;
			dfs(i);
		}
	}
}

int main()
{
	int m;
	cin >> m;
	int minnum = 0x3f3f3f3f;
	for(int i = 0;i < m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		minnum = min(minnum,min(a,b));
		mp[a][b] = mp[b][a] = 1;
		mp[a][0]++;
		mp[b][0]++;
		if(a > n)	n = a;
		if(b > n)	n = b;
	}
	int flag = 0;
	for(int i = 1;i <= n;i++){
		if(mp[i][0] % 2 == 1){
			flag = i;
			break;
		}
	}
	if(flag != 0)
		dfs(flag);
	else
		dfs(minnum);
	
	
	return 0;
} 
