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
const LL M = 1e9 + 7; 

int main()
{
	int T;
	cin >> T;
	while(T--){
		int x;
		scanf("%d",&x);
		string s;
		cin >> s;
		int k = 0;
		while(s.length() < x){
			int num = s[k] - '0';
			string t;
			t = s.substr(k+1);
			s = s.substr(0,k+1);
			while(num--)
				s += t;
			k++;
		}
		LL ans = s.length();
		while(k < x){
			ans = k + 1 + (s[k] - '0') *  (ans - k - 1);
			k++;
		}
		printf("%d\n",ans);
	}
	return 0;
}

