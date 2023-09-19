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
	LL n;
	cin >> n;
	LL tmp = 10;
	LL ans = 0;
	if(n % 2 == 1){
		printf("0\n");
	}
	else{
		ans += n / 10;
		n /= 10;
		while(n > 0){
			ans += n / 5;
			n /= 5;
		}
		cout << ans << endl;
	}
	return 0;
}

