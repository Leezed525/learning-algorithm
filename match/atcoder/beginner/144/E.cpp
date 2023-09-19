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
const int MAXN = 2 * 1e5 + 5;
int a[MAXN];
int b[MAXN];
struct node{
	int a;
	int b;
	long long c;
	
};
bool operator < (node d,node a)
{
	return a.c > d.c;
} 
bool cmp(int a,int b){
	return a > b;
} 
int main()
{
	int n;
	long long k,sum = 0;
	scanf("%d %d",&n,&k);
	for(int i = 0;i < n;i++)
		scanf("%d",&a[i]),sum += a[i];
	for(int i = 0;i < n;i++)
		scanf("%d",&b[i]);
	if(sum <= k){
		printf("0");
		return 0;
	}
	sort(a,a+n);
	sort(b,b+n,cmp);
	priority_queue<node> q;
	for(int i = 0;i < n;i++){
		node tmp;
		tmp.a = a[i];
		tmp.b = b[i];
		tmp.c = a[i] * b[i];
		q.push(tmp);
	}
	while(k > 0){
		node x = q.top();q.pop();
		node y = q.top();
		long long t = x.c - y.c;
		int z = t / x.b + 1;
		if(z > k)
			z = k;
		k -= z;
		x.c -= x.b * z;
		x.a -= z;
		q.push(x);
		if(x.c == 0)
			break;
	}
	node x = q.top();
	cout << x.c<< endl;
	return 0;
}

