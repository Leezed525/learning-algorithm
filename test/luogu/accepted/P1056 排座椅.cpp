#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3+5;
struct node{
	int line;
	int num;
}r[MAXN],w[MAXN];

bool cmp(node a,node b)
{
	return a.num > b.num;
}

bool cmp1(node a,node b){
	return a.line < b.line;
}
int main()
{
	int m,n,k,l,d;
	cin >> m >> n >> k >> l >> d;
//	int mp[m + 1][n + 1];
//	memset(mp,0,sizeof(mp));
	for(int i = 1;i <= m;i++){	r[i].line = i;r[i].num = 0; }
	for(int i = 1;i <= n;i++){  w[i].line = i;w[i].num = 0; }	
	for(int i = 1;i <= d;i++){
		int x,y,a,b;
		scanf("%d %d %d %d",&x,&y,&a,&b);
		if(x == a)
			w[min(y,b)].num++;
		else
			r[min(a,x)].num++;
	}
	sort(r+1,r+1+m,cmp);
	sort(w+1,w+1+n,cmp);
	sort(r+1,r+1+k,cmp1);
	sort(w+1,w+1+l,cmp1);
	for(int i = 1;i <= k;i++)
		printf("%d%c",r[i].line,i == k?'\n':' ');
	for(int i = 1;i <= l;i++)
		printf("%d%c",w[i].line,i == l?'\n':' ');
	return 0;
}
