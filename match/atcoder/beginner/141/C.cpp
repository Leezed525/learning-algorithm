#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k,q;
	cin >> n >> k >> q;
	int a[n+1];
	memset(a,0,sizeof(a));
	for(int i = 0;i < q;i++){
		int t;
		scanf("%d",&t);
		a[t]++;
	}
	for(int i = 1;i <= n;i++){
		if(q - a[i] > k - 1)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}
