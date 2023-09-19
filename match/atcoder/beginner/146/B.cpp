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
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int i = 0;i < s.length();i++){
		printf("%c",(s[i] - 'A' + n) % 26 + 'A');
	}
	cout << endl;
	return 0;
}

