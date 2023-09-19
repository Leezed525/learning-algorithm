#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3+5;
struct node{
	int id;
	int time;
};
node a[MAXN];
bool cmp(node a, node b)
{
	if(a.time == b.time)
		return a.id < b.id;
	else
		return a.time < b.time;
}
int main()
{
	int n;
	long long  sum = 0;
	cin >> n;
	for(int i = 0;i < n;i++)	scanf("%d",&a[i].time),a[i].id = i + 1;
	sort(a,a + n,cmp);
	for(int i = 0;i < n;i++){
		sum += ((n - 1 - i) * a[i].time);
		printf("%d%c",a[i].id,i == n - 1?'\n':' ');
	}
	printf("%.2lf",sum* 1.0 / n);
}
