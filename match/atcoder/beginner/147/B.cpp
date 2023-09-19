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
	string s;
	cin >> s;
	int ans = 0;
	for(int i = 0;i < s.length()/2;i++){
		if(s[i] != s[s.length() - 1 - i])
			ans++;
	}
	cout << ans << endl;
	return 0;
}

