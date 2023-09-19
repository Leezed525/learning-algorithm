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
		int n;
		scanf("%d",&n);
		map<int,int>m;
		priority_queue<int>q;
		for(int i = 0;i < n;i++){
			int x;
			scanf("%d",&x);
			if(!(x&1)){
				if(m[x] != 1){
					m[x] = 1;
					q.push(x);
				}
			}
		}
		int ans = 0;
		while(!q.empty()){
			int x = q.top();
			q.pop();
			if(m[x / 2] != 1 && !((x / 2) & 1)){
				m[x / 2] = 1;
				q.push(x / 2);
			}
			ans++;
		}
		cout << ans << endl ;
	}
	return 0;
}

