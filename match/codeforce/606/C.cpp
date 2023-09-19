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
		cin >> s;
		int len = s.length();
		set<int>ans;
		for(int i = 0;i < len - 2;i++){
			if(i < len - 4 && s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o' && s[i+3] == 'n' && s[i+4] == 'e'){
				ans.insert(i + 3);
				s[i + 2] = 'z';
			}
				
			else if(s[i] == 'o' && s[i+1] == 'n' && s[i+2] == 'e')
				ans.insert(i+2);
			else if(s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o') 
				ans.insert(i + 2);
		}
		cout << ans.size() << endl;
		set<int>:: iterator it;
		for(it = ans.begin();it != ans.end();it++){
			if(it != ans.begin())
				printf(" ");
			printf("%d",*it);
		}
		printf("\n");
	} 
	return 0;
}
