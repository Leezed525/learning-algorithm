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
struct node{
	int num;
	int pos;
}a[MAXN];

bool cmp(node a,node b)
{
	if(a.num == b.num){
		return a.pos < b.pos;
	}
	else
		return a.num < b.num;
}

int main()
{
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		for(int i = 1;i <= n;i++){
			scanf("%d",&a[i].num);
			a[i].pos = i;
		}
		sort(a+1,a+n+1,cmp);
		int minn = INF;
		for(int i = 2;i <= n;i++){
			if(a[i].num == a[i - 1].num){
				minn = min(minn,a[i].pos - a[i - 1].pos + 1);
			}
		}
		if(minn == INF)
			printf("-1\n");
		else
			printf("%d\n",minn);
	}
	
	return 0;
}

