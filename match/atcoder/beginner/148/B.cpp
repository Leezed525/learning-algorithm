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
	string s1,s2;
	int n;
	cin >> n >> s1 >> s2;
	for(int i = 0;i < n;i++){
		printf("%c%c",s1[i],s2[i]);
	}
	printf("\n");
	return 0;
}

