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
	cin >>s;
	if(s == "SUN")
		cout << 7 <<endl;
	else if(s == "MON")
		cout << 6 <<endl;
	else if(s == "TUE")
		cout << 5 <<endl;
	else if(s == "WED")
		cout << 4 <<endl;
	else if(s == "THU")
		cout << 3 <<endl;
	else if(s == "FRI")
		cout << 2 <<endl;
	else if(s == "SAT")
		cout << 5 <<endl;
	return 0;
}

