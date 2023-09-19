#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#include<sstream>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e2 +5 ;
struct node{
	int val;
	int id;
}n1[MAXN];

bool cmp(node a,node b)
{
	if(a.val == b.val)
		return a.id < b.id;
	else
		return a.val > b.val;
}

bool cmp1(node a,node b){
	return a.id < b.id;
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		scanf("%d",&n1[i].val);
		n1[i].id = i;
	}
	sort(n1,n1 + n,cmp);
	int m;
	cin >> m;
	for(int i = 0;i < m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		node m1[a];
		for(int i = 0;i < a;i++){
			m1[i] = n1[i];
		}
		sort(m1,m1 + a,cmp1);
		printf("%d\n",m1[b - 1].val);
	}
	return 0;
}

