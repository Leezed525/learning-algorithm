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
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		if(d / c < a){
			d = d - d / c * c;
			if(d > b)
				printf("NO\n");
			else
				printf("YES\n");
		}
		else{
			d = d - a * c;
			if(d > b)
				printf("NO\n");
			else
				printf("YES\n");
		}
	}
	return 0;
}

