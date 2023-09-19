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
		map<char,int>mp;
		string s;
		cin >> s;
		int len = s.length();
		for(int i = 0;i < len;i++){
			mp[s[i]]++;
		}
		int ans = 0;
		mp['L'] = mp['R'] = min(mp['L'],mp['R']);
		mp['U'] = mp['D'] = min(mp['U'],mp['D']);
		if(mp['L'] == 0 && mp['U'] != 0){
			printf("2\nUD\n");
			continue;
		}
		if(mp['U'] == 0 && mp['L'] != 0){
			printf("2\nLR\n");
			continue;
		}
		ans += mp['L'] * 2 + mp['U'] * 2;
		printf("%d\n",ans);
		while(mp['L']--){
			printf("L");
		}
		while(mp['U']--)
			printf("U");
		while(mp['R']--)
			printf("R");
		while(mp['D']--)
			printf("D");
		printf("\n");
	}
	return 0;
}

