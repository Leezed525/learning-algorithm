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
const int MAXN = 1e6 + 5;
int mp[MAXN];

int main()
{
	int T;
	cin >> T;
	while(T--){
		memset(mp,0,sizeof(mp));
		int n;
		cin >> n;
		int a[n];
		for(int i = 0;i < n;i++){
			scanf("%d",&a[i]);
			mp[a[i]]++;
		}
		if(n < 6){
			printf("0 0 0\n");
			continue;
		}
		int sum = 0,num = 0;
		for(int i = 0;i < n;i += mp[a[i]]){
			if(sum + mp[a[i]] <= n / 2){
				sum += mp[a[i]];
				num++;
			}
			else{
				break;
			}
		}
		if(num < 3){
			printf("0 0 0\n");
			continue;
		}
		int jin = 0,yin = 0,tong = 0;
		int flag = 0;
		for(int i = 0;i < n;i += mp[a[i]]){
			if(flag == 0){
				jin = mp[a[i]];
				if(jin >= sum /2){
					flag = -1;
					break;
				}
				else
					flag = 1;
			}
			else if(flag == 1){
				yin += mp[a[i]];
				if(yin > jin){
					tong = sum - jin - yin;
					break;
				}
			}
		}
		if(tong > jin)
			printf("%d %d %d\n",jin,yin,tong);
		else 
			printf("0 0 0\n");
	}
	return 0;
}

