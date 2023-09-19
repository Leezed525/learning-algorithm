#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
int a[MAXN];

void qsort(int l,int r)
{
	int mid = a[(l + r) / 2];
	int i = l,j =r;
	do{
		while(a[i] < mid)
			i++;
		while(a[j] > mid)
			j--;
		if(i <= j){
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}while(i <= j);
	if(l < j)	qsort(l,j);
	if(i < r)	qsort(i,r);
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
		scanf("%d",&a[i]);
	qsort(0,n - 1);
	for(int i = 0;i < n;i++)
		printf("%d%c",a[i],i == n - 1?'\n':' ');
}
