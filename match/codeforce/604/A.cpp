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
char c[3] = {'a','b','c'};

int main()
{
	int T;
	cin >> T;
	while(T--){
		string s,ans;
		cin >> s;
		int len = s.length();
		int flag = 0;
		for(int i = 1;i < len;i++){
			if(s[i] == s[i - 1] && s[i] != '?'){
				flag = 1;
				break;
			} 
		}
		if(flag){
			printf("-1\n");
			continue;
		}
		for(int i = 0;i < len;i++){
			if(s[i] == '?'){
				if(i == len - 1){
					for(int j = 0;j < 3;j++){
						if(c[j] != s[i - 1] && c[j] != ans[i - 1]){
							ans += c[j];
							break;
						}
					}
				}
				else if(i == 0){
					for(int j = 0;j < 3;j++){
						if(c[j] != s[i + 1]){
							ans += c[j];
							break;
						}
					}
				}
				else{
					for(int j = 0;j < 3;j++){
						if(c[j] != s[i + 1] && c[j] != s[i - 1] && c[j] != ans[i - 1]){
							ans += c[j];
							break;
						}
					}
				}
			}
			else
				ans += s[i];
		}
		cout << ans << endl; 
	} 
	return 0;
}

