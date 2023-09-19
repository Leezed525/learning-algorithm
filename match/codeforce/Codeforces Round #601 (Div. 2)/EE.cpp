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

bool isprime(int x)
{
	for(int i = 2;i * i <= x;i++){
		if(x % i == 0)
			return false;
	}
	return true;
}

int gcd(int a,int b)
{
	return b == 0?a:gcd(b,a%b);
}

int main()
{
	for(int i = 2;i <= 1e5;i++){
		if(isprime(i))
			for(int j = 4;j + j <= i;j++){
				if(gcd(j,i - j) != 1)
					printf("%d\n",i);
			}
	}
	return 0;
}

