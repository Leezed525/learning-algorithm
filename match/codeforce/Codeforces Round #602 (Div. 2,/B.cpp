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
int a[MAXN],biaoji[MAXN];
int main()
{
	int T;
	cin >> T;
	while(T--){
		int n,tmp = 1,flag = 0;
		scanf("%d",&n);
		memset(biaoji,0,sizeof(biaoji));
		int b[n];
		for(int i = 0;i < n;i++){
			scanf("%d",&a[i]);
		}
		b[0] = a[0];
		biaoji[a[0]] = 1;
		for(int i = 1;i < n;i++){
			if(a[i] > a[i - 1]){
				b[i] = a[i];
				biaoji[a[i]] = 1;
			}
			else if(a[i] == a[i - 1]){
				int fg = 1; 
				while(tmp < a[i]){
					if(!biaoji[tmp]){
						b[i] = tmp;
						biaoji[tmp++] = 1;
						fg = 0;
						break;
					}
					tmp++;
				}
				if(fg){
					flag = 1;
					break;
				}
			}
			else
				flag = 1;
		}
		if(flag)
			printf("-1\n");
		else{
			for(int i = 0;i < n;i++){
				printf("%d ",b[i]);
			}
			printf("\n");
		}
	}
	return 0;
}

