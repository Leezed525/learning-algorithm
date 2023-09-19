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
const int MAXN = 1e5+5;
__int64 f[MAXN];
int m = 1e9 + 7;
void dabiao()
{
	f[0] = 1;
	f[1] = 1;
	for(int i = 2;i < MAXN;i++){
		f[i] = f[i - 1] + f[i - 2];
	} 
}

int main()
{
	dabiao();
	string s;
	cin >> s;
	long long sum = 1;
	int len = s.length();
	int tmp = 1;
	if(s[0] == 'm' || s[0] == 'w' ){
		printf("0\n");
		return 0;
	}
	for(int i = 1;i < len;i++){
		if(s[i] == 'm' || s[i] == 'w'){
			printf("0\n");
			return 0;
		}
		if(s[i] == s[i - 1] && (s[i] == 'u' || s[i] == 'n')){
			tmp++;
		}
		else{ 
			sum = (sum * f[tmp]) % m;
			tmp = 1;
		}	
	}
	sum = (sum * f[tmp]) % m;
	cout << sum << endl;
	return 0;
}

