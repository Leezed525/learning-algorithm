#include <bits/stdc++.h>
using namespace std;
const int N = 20;
 
int s[N],per[N][N],is[N][N];
 
inline int cal(int x){
	int res = 0;
	while(x){
		x -= (x&(-x));
		res++;
	}
	return res;
}
 
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;++i){
		scanf("%d",&s[i]);
		for(int j = 1;j <= s[i];++j){
			scanf("%d%d",&per[i][j],&is[i][j]);
		}
	}
	
	int ans = 0;
	for(int i = 0;i < (1<<n);++i){
		bool f = 1;
		for(int j = 1;j <= n;++j){
			if(i & (1 << (j-1))){
				for(int k = 1;k <= s[j];++k){
					if(is[j][k] && !(i & (1 << per[j][k]-1))) f = 0;
					if(!is[j][k] && (i & (1 << per[j][k]-1))) f = 0;
					if(!f) break; 
				}
			}
			if(!f) break;
		}
		if(f) ans = max(ans,cal(i));
	}
	
	printf("%d\n",ans);
	return 0;
}
