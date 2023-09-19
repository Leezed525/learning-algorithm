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
		string s;
		cin >>s;
		string tmp;
		tmp = s.substr(s.length() - 2,2);
		if(tmp == "po")
			printf("FILIPINO\n");
		else if(tmp == "su")
			printf("JAPANESE\n");
		else
			printf("KOREAN\n");
	}
	return 0;
}

