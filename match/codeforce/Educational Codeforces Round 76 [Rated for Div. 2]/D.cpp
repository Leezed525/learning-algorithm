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
int monster[MAXN];
struct node1{
	int health;
	int counts;
}hero[MAXN];

bool cmp(node1 a,node1 b){
	if(a.counts == b.counts)
		return a.health > b.health;
	return a.counts > b.counts;
}

int main()
{
	int T;
	cin >> T;
	while(T--){
		int n,m,flag = 0;
		cin >> n;
		for(int i = 0;i < n;i++)
			scanf("%d",&monster[i]);
		cin >> m;
		for(int i = 0;i < m;i++){
			scanf("%d%d",&hero[i].health,&hero[i].counts);
		}
		sort(monster,monster+n);
		sort(hero,hero + m,cmp);
		int ans = 0;
		int j = 0,t = 0,health,counts;
		while(j < n){
			int maxn = 0;
			for(int i = 0;i < m;i++){
				int tj = j;
				if(hero[i].health < monster[tj]){
					continue;
				}
				health = hero[i].health;
				counts = hero[i].counts;
				while(health >= monster[tj] && counts != 0){
						health -= monster[tj++];
						counts--;
				}
				maxn = max(maxn,tj - j);
			}
			if(maxn == 0){
				flag = 1;break;
			}
			else{
				j += maxn;
				ans++;
			}
				
		}
		if(flag == 1)
			printf("-1\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}

