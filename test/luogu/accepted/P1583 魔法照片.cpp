#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2 * 1e4 + 5;
struct node{
	int id;
	int num;
}n1[MAXN];
int e[11];
bool cmp(node a ,node b)
{
	if(a.num == b.num)
		return a.id < b.id;
	return a.num > b.num;
}

int main()
{
	int n,k;
	cin >> n >> k;
	for(int i = 1;i <= 10;i++){
		cin >> e[i];
	}
	for(int i = 1;i <= n;i++){
		scanf("%d",&n1[i].num);
		n1[i].id = i;
	}
	sort(n1 + 1,n1 + 1 + n,cmp);
	for(int i = 1;i <= n;i++){
		n1[i].num += e[(i - 1)%10 + 1];
	}
	sort(n1 + 1,n1 + 1 + n,cmp);
	for(int i = 1;i <= k;i++){
		cout << n1[i].id << " ";
	}
	return 0;
}
