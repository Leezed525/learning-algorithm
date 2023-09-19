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
		int a,b;
		cin >> a >> b;
		if(a == 1){
			if(b == 1){
				printf("YES\n");
			}
			else{
				printf("NO\n");
			}
		}
		else if(a == 2 && b == 3){
			printf("YES\n");
		}
		else if(a < 4 && a < b){
			printf("NO\n");
		}
		else 
			printf("YES\n");
	}
	return 0;
}

