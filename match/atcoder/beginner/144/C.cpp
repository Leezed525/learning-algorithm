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
	long long a;
	cin >> a;
	long long ans = 0,ans1 = 0;
	for(int i = 1;i <= sqrt(a);i++){
		if(a % i == 0){
			ans = i;
			ans1 = a/i;
		}
	}
	cout << ans + ans1 - 2<< endl;
	return 0;
}

