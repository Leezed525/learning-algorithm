#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3+5;
int a[MAXN];
int main()
{
	int n;
	cin >> n;
	int sum = 0;
	for(int i = 0;i < n;i++){
		scanf("%d",&a[i]);
		sum += a[i];
	}
	sum = sum / n;
	int ans = 0;
	for(int i = 0;i < n;i++){
		a[i] -= sum;
		if(a[i] > 0){
			a[i + 1] += a[i];
			ans++;
		}
		else if(a[i] < 0){
			a[i + 1] += a[i];
			ans++;
		}	
	}
	cout << ans << endl;
	return 0;
} 
