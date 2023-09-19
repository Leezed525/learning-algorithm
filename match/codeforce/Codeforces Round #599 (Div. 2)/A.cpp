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
const int MAXN = 1e3+5;
int a[MAXN];

bool cmp(int a,int b){
	return a > b;
}

int main()
{
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		memset(a,0,sizeof(a));
		for(int i = 0;i < n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n,cmp);
		int i;
		for(i = 0;i < n;i++){
			if(a[i] < i + 1)
				break;
		}
		printf("%d\n",i);
	}
	return 0;
}

