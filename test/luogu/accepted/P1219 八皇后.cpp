#include<bits/stdc++.h>
using namespace std;
int sum = 0,biaoji[14],mp[14];
int n;

bool check(int x,int num)
{
	if(biaoji[num] == 1)	
		return false;
	for(int i = 0;i < x;i++){
		if(mp[i] != 0){
			if(mp[i] == num || x-num==i-mp[i]|| x+num==i+mp[i])
				return false ;
		}
	}
	return true;
}

void dfs(int x)
{
	if(x == n){
		if(sum < 3){
			for(int i = 0; i < n;i++)
				printf("%d%c",mp[i],i == n - 1?'\n':' ');
		}
		sum++;
		return ; 
	}
	for(int i = 1;i <= n;i++){
		if(check(x,i)){
			biaoji[i] = 1;
			mp[x] = i;
			dfs(x + 1);
			mp[x] = 0;
			biaoji[i] = 0;
		}
	}
}

int main()
{
	cin >> n;
	dfs(0);
	cout << sum << endl;
	return 0;
}
