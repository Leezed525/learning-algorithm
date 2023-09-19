#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int a[n];
	int b[n];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(int i = 0;i < n - 1;i++)
		scanf("%d",&b[i]);
	b[n - 1] = b[n - 2];
	a[0] = b[0];a[1] = b[0];
	for(int i = 1;i < n;i++){
		a[i] = min(b[i - 1],b[i]);
	}
	long long sum = 0; 
	for(int i = 0;i < n;i++){
		sum += a[i];
	}
	cout << sum << endl;
	return 0;
}
