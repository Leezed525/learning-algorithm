#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3 * 1e4 + 5;
int a[MAXN];
bool fg[MAXN];
int main()
{
	int m,n;
	cin >> m >> n;
	memset(fg,false,sizeof(fg));
	for(int i = 0;i < n;i++)	scanf("%d",&a[i]);
	sort(a,a + n ); 
	int wei = n - 1,ans = 0,t = 0;
	while(!fg[wei]){
		if(a[wei] + a[t] <= m){
			wei--;
			ans++;
			fg[t++] = true;
		}
		else{
			wei--;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
} 
