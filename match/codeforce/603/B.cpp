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
const int MAXN = 1e2 +5; 
struct node{
	int num;
	int id;
}n1[MAXN];

bool cmp(node a,node b)
{
	return a.num < b.num;
}
bool cmp1(node a,node b)
{
	return a.id < b.id;
}
map<int,int>mp;
int main()
{
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		mp.clear();
		int ans = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d",&n1[i].num);
			mp[n1[i].num]++;
			n1[i].id = i;
		}
		sort(n1 + 1,n1 + 1 + n,cmp);
		for(int i = 2;i <= n;i++){
			if(mp[n1[i].num] > 1){
				ans++;
				int num = n1[i].num / 10;
				for(int j = 0;j <= 9;j++){
					if(mp[num * 10 + j] == 0){
						mp[n1[i].num]--;
						n1[i].num = num * 10 + j;
						mp[n1[i].num]++;
						break;
					}
				}
			}
		}
		sort(n1 + 1,n1 + 1 + n,cmp1);
		printf("%d\n",ans);
		for(int i = 1;i <= n;i++){
			printf("%04d\n",n1[i].num);
		}
	}
	return 0;
}

