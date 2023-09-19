#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e2+5;
int mp[MAXN][MAXN];
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		mp[a][b] = 1;
	}
	for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(mp[i][k] && mp[k][j]) mp[i][j] = 1;
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
    	int t = 0;
    	for(int j = 1;j <= n;j++){
    		if(mp[i][j])	t++;
		}
		if(t >= (n + 1) / 2){
			ans++;
		}
		t = 0;
		for(int j = 1;j <= n;j++){
			if(mp[j][i])	t++;
		}
		if(t >= (n + 1) / 2)
			ans++;
	}
	cout << ans << endl;
}
