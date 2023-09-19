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
int mp[MAXN];

int main()
{
	int T;
	cin >> T;
	while(T--){
		memset(mp,0,sizeof(0));
		int n;
		cin >> n;
		int a[n + 1];
		int maxn = -INF,minn = INF;
		for(int i = 1;i <= n;i++){
			scanf("%d",&a[i]);
			mp[a[i]] = i;
		}
		for(int i = 1;i <= n;i++){
			maxn = max(maxn,mp[i]);
			minn = min(minn,mp[i]);
			if(maxn - minn <= i - 1){
				printf("1");
			}
			else
				printf("0");
		}
		printf("\n");
	}
	return 0;
}

