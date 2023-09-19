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

int dig(LL x)
{
	int ans = 0;
	while(x != 0){
		x /= 10;
		ans++;
	}
	return ans;
}

int main()
{
	LL a,b,x;
	cin >> a >> b >> x ;
	int l = 1,r = 1e9;
	if(x >= 1e9){
		r = 1e9;
	}
	else
		r = x;
	int mid;
	while(l < r){
		mid = (l + r) / 2;
		LL c = mid * a + dig(mid) * b;
		if(c <= x){
			l = mid + 1;
		}
		else
			r = mid;
	}
	
	if(l * a + dig(l) * b > x)
		l--;
	cout << l <<endl;
	
	return 0;
}

