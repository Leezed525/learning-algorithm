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
	int n;
	cin >> n;
	int ans = 0,tmp = 1,pos = 0;
	for(int i = 0;i < n;i++){
		int x;
		scanf("%d",&x);
		if(x == tmp){
			tmp++;
		}
	}
	if(tmp == 1)
		printf("-1\n");
	else
		cout << n - tmp + 1 << endl;
	return 0;
}

