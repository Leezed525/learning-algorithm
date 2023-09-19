#include<bits/stdc++.h>
using namespace std;
int n,m;
int tree[530000];
int main()
{
	cin >> n >> m;
	int j;
	for(int i = 1;i<=m;i++){
		for(j = 1;j<=pow(2,n-1)-1;j++){
			if(tree[j] == 0){
				tree[j]=1;
				j=j*2-1;
			}
			else{
				tree[j]=0;
				j=j*2;
			}
		}
	}
	printf("%d\n",j);
} 
