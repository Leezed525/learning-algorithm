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
		LL a,b;
		cin >> a >> b;
		if(a * 2 >= b && b * 2 >= a){
			long long sum = a+b;
			if(sum % 3 == 0){
				printf("YES\n");
			}
			else
				printf("NO\n");
		}
		else
			printf("NO\n");
		
	}
	return 0;
}

