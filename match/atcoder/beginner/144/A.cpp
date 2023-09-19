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
	int a,b;
	cin >> a >> b;
	if(a >= 1 && a <= 9 && b >= 1 && b <= 9)
		cout << a*b<<endl;
	else	
		cout << -1 << endl;
	return 0;
}

