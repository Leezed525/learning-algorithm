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
		int a[3],sum = 0;
		for(int i = 0;i < 3;i++)
		{
			scanf("%d",&a[i]);
			sum += a[i];
		}
		sort(a,a + 3);
		cout << min(sum / 2,(a[0] + a[1])) << endl;
		
	}
	return 0;
}

