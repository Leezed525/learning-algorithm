#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5 * 1e3 + 5;
struct node{
	int id;
	int num;
}n1[MAXN];

bool cmp(node a ,node b)
{
	if(a.num == b.num)
		return a.id < b.id;
	return a.num > b.num;
}

int main()
{
	int n,m;
	cin >> n >> m;
	m = m * 1.5 / 1;
	for(int i = 0;i < n;i++){
		scanf("%d %d",&n1[i].id,&n1[i].num); 
	}
	sort(n1,n1+n,cmp);
	printf("%d ",n1[m - 1].num);
	while(n1[m].num == n1[m - 1].num)	
		m++;
	printf("%d\n",m);
	for(int i = 0;i < m;i++){
		printf("%d %d\n",n1[i].id,n1[i].num);
	}
	return 0;
}
