#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
struct node{
	int st;
	int et;
}n1[MAXN];
bool cmp(node a,node b)
{
	return a.et < b.et;
}
int main()
{
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)	scanf("%d %d",&n1[i].st,&n1[i].et);
	sort(n1,n1 + n,cmp);
	int ans = 0,st = 0;
	for(int i = 0;i < n;i++){
		if(n1[i].st >= st){
			ans++;
			st = n1[i].et;
		}
	}
	cout << ans << endl;
	return 0;
}
