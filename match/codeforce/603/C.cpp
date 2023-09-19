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
		set<int>s;
		int n;
		cin >> n;
		s.insert(0);
		for(int i = 1;i * i <= n;i++){
			s.insert(i);
			s.insert((n / i));
		}
		printf("%d\n",s.size());
		set<int>::iterator it;
		for(it = s.begin();it != s.end();it++){
			printf("%d ",*it);
		}
		cout << endl;
	}
	return 0;
}

