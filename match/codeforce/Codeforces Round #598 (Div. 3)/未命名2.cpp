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
const int MAXN = 1e2 + 5;  
int a[MAXN],book[MAXN];

int main()
{
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		int len = n;
		memset(a,0,sizeof(a));
		for(int i = 1;i <= n;i++){
			scanf("%d",&a[i]);
			book[a[i]] = i;
		}
		for(int i = 1;i <= len && n > 1;i++){
			if(a[i] != i){
				int j = i + 1;
				while(a[j] != i)j++;
				for(int k = j;k >= i + 1;k--){
					swap(a[k],a[k - 1]);
					n--;
					if(n <= 1)
						break;
				}
			}
		}
		for(int i = 1;i <= len;i++){
			printf("%d%c",a[i],i == len?'\n':' ');
		}
	}
	return 0;
}

