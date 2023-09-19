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
		int a[3];
		LL sum = 0;
		for(int i = 0;i < 3;i++){
			scanf("%d",&a[i]);
			sum += a[i];
		}
		LL ans = 0;
		for(int i = 0;i < 3;i++){
			for(int j = i + 1;j < 3;j++){
				ans += abs(a[j] - a[i]);
			}
		}
		cout << max(ans - 4,0LL) <<endl;
//		sort(a,a + 3);
//		for(int i = 0;i < 3;i++){
//			if(a[i] < sum / 3)
//				a[i]++;
//			else if(a[i] > sum / 3 )
//				a[i]--;		
//		}
//		LL ans = 0;
//		for(int i = 0;i < 3;i++){
//			for(int j = i + 1;j < 3;j++){
//				ans += a[j] - a[i];
//			}
//		}
//		cout << ans << endl;
	}
	return 0;
}

