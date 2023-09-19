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
const int MAXN = 2 * 1e5 + 5;
int biaoji[MAXN];
vector<char>v;

int main()
{
	int n,m;
	cin >> n>>m;
	string s;
	cin >> s;
	for(int i = 0;i < m;i++){
		char ch;
		scanf(" %c",&ch);
		v.push_back(ch);
	}
	int sss = v.size();
	for(int i = 0;i < n;i++){
		for(int j = 0;j < sss;j++){
			if(s[i] == v[j]){
				biaoji[i] = 1;
				break;
			}
		}
	}
	LL tmp = 0;
	LL ans = 0;
	for(int i = 0;i < n + 1;i++){
		if(biaoji[i] == 0){
			ans += (1 + tmp) * tmp / 2;
			tmp = 0;
		}
		else
			tmp++;
	}
	cout << ans << endl;
	return 0;
}

