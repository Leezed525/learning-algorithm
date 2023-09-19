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

LL gcd(LL a, LL b)
{
	return b == 0?a:gcd(b,a%b);
}

LL acm(LL a,LL b)
{
	return a / gcd(a,b) * b;
}

int main()
{
	LL n,m;
	cin >> n >> m;
	LL ans = acm(n,m);
	cout << ans <<endl;
	return 0;
}

