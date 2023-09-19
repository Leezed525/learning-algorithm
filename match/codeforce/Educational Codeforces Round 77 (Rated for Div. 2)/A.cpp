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
		int n,m;
		cin >> n >> m;
		long long ans = 0;
		while(n > 0){
			int tmp = m / n;
			m -= tmp;
			ans += tmp * tmp;
			n--;
		}
		cout << ans << endl;
	} 
	return 0;
}

