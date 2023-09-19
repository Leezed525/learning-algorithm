#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;
int a[MAXN];
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < n;i++)	scanf("%d",&a[i]);
	long long sum = 0;
	int ans = 0;
	for(int i = 0;i < n;i++){
		sum += a[i];
		if(sum > m){
			ans++;
			sum = a[i];
		}
	}
	cout << ans + 1 << endl;
	return 0;
} 
