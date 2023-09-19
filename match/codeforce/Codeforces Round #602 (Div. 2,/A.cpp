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


int main()
{
	int T;
	cin >> T;
	while(T--){
		int n;
		scanf("%d",&n);
		int minn = INF,maxn = -INF;
		for(int i = 0;i < n;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			maxn = max(maxn,a);
			minn = min(minn,b);
		}
		cout << max(0,maxn - minn) <<endl;
	} 
	return 0;
}

