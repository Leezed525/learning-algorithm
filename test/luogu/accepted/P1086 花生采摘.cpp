#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500;
struct node{
	int num;
	int i;
	int j;
}a[MAXN];

bool cmp(node a,node b)
{
	return a.num > b.num;
}

int main()
{
	int m,n,k;
	int nn = 0;
	cin >> m >> n >> k;
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= n;j++){
			int t;
			scanf("%d",&t);
			if(t == 0)
				continue;
			else{
				a[nn].num = t;
				a[nn].i = i;
				a[nn++].j = j;
			}
		}
	}
	sort(a,a + nn,cmp);
	k-=2;
	int time = 2,y = a[0].j,x = 1,ans = 0;
	for(int i = 0;i < nn;i++){
		if(k - abs(a[i].i - x) - abs(a[i].j - y) - 1 - abs(a[i].i - 1) >= 0){
			k = k - abs(a[i].i - x) - abs(a[i].j - y) - 1;
			x = a[i].i;
			y = a[i].j;
			ans += a[i].num;
		}
		else
			break;
	}
	cout << ans << endl;
	return 0;
} 
