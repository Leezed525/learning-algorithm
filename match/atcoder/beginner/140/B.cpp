#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e2+5;
int a[MAXN],b[MAXN],c[MAXN],biaoji[MAXN];

int main()
{
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)	scanf("%d",&a[i]);
	for(int i = 0;i < n;i++)	scanf("%d",&b[i]);
	for(int i = 0;i < n - 1;i++)	scanf("%d",&c[i]);
	long long sum = 0;
//	memset(biaoji,0,sizeof(biaoji));
//	for(int i = 0;i < n;i++){
//		sum += b[a[i] - 1];
//		biaoji[a[i] - 1] = 1;
//		if(biaoji[a[i] - 2] == 1)
//			sum += c[a[i] - 2];
//	}
	sum += b[a[0] - 1];
	for(int i = 1;i < n;i++){
		if(a[i] - 1 == a[i - 1])
			sum += c[a[i - 1] -  1];
		sum += b[a[i] - 1];
	}
	cout << sum << endl;
	return 0;
}
