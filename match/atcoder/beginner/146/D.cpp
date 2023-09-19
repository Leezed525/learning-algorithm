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
const int MAXN = 1e5 + 5;
int counts = 1,maxn = -INF;
int head[MAXN];
struct node{
	int to;
	int next;
	int color;
}edge[MAXN];

void addedge(int a,int b)
{	
	edge[counts].to = b;
	edge[counts].color = 0;
	edge[counts].next = head[a];
	head[a] = counts++;
}

void dfs(int u,int c)
{
	int tmp = 1;
	for(int i = head[u];i != 0;i = edge[i].next){
		int v = edge[i].to;
		if(tmp == c)
			tmp++;
		edge[i].color = tmp;
		maxn = max(maxn,tmp);
		dfs(v,tmp);
		tmp++;
	}
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0;i < n - 1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		addedge(a,b);
	}
	dfs(1,0);
	printf("%d\n",maxn);
	for(int i = 1;i < counts;i++){
		printf("%d\n",edge[i].color);
	}
	return 0;
}

