#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5 * 1e3+5;
struct node{
	int p,a;
}n1[MAXN];

bool cmp(node a,node b)
{
	return a.p < b.p;
}
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < m;i++)	scanf("%d %d",&n1[i].p,&n1[i].a);
	sort(n1,n1 + m,cmp);
	long long ans = 0;
	for(int i = 0;i < m;i++){
		if(n > n1[i].a){
			ans += n1[i].a * n1[i].p;
			n -= n1[i].a;
		}
		else{
			ans += n1[i].p * n;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
