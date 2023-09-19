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
		cin >> n;
		int num = 0,x = n;
		while(x > 0){
			num++;
			x /= 10;
		}
		int ans = (num - 1) * 9;
		int tmp = 0;
		for(int i = 0;i < num;i++){
			tmp = tmp * 10 + 1;
		}
		int atmp = tmp;
		while(atmp <= n){
			atmp += tmp;
			ans++;
		}
		cout << ans << endl;
	} 
	return 0;
}

