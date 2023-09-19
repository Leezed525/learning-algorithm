#include<bits/stdc++.h>
using namespace std;
int n, m[100],sum=0,ans[100],aaa=0;

bool check(int y,int x)
{
	for(int i = 0;i < x;i++){
		if(m[i] == y||(abs(m[i]-y)) == abs(i-x)){
			return false;
		}
	}
	return true;
}

void dfs(int x)
{
	if(x == n){
		if(aaa<3){
			for(int i = 0 ;i < n;i++){
				if(i == 0)printf("%d",m[i]+1);
				else printf("% d",m[i]+1);
			}
			printf("\n");
			aaa++;
		}
		
		sum++;
		return ;
	}
	for(int y=0;y<n;y++){
		
		if(check(y,x)){
			m[x]=y;
			dfs(x+1);
		}
	}
}

int main()
{
	for(int i=0;i<100;i++){
		ans[i]=-1;
	}
	cin >> n;
	 
//	while(cin >> n){
//		if(n == 0) break;
		 if(ans[n] == -1){
			memset(m,0,sizeof(m));
			sum=0; 
			dfs(0);
			ans[n]=sum;
			printf("%d\n",ans[n]);
		}
		else {
			printf("%d\n",ans[n]);
		}
//	}
	return 0;
}
