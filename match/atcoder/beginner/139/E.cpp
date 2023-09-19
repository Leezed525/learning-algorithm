#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000+5;
queue<int>q[MAXN];
bool biaoji[MAXN];
int n;
bool pan()
{
	for(int i = 1;i <= n;i++){
		if(!q[i].empty()) return false;
	}
	return true;
}
int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n-1;j++){
			int t;
			scanf("%d",&t);
			q[i].push(t);
		}
	}
	for(int i = 1;;i++){
		memset(biaoji,true,sizeof(biaoji));
		if(pan()){
			cout << i - 1 << endl;
			break;
		}
			
		int flag = 0;
		for(int j = 1;j <= n;j++){
			if(biaoji[j] && !q[j].empty()){
				int t = q[j].front();
				if(biaoji[t] && !q[t].empty() && q[t].front() == j){
					biaoji[j] = false;
					biaoji[t] = false;
					flag = 1;
					q[j].pop();
					q[t].pop();
				}
			}
		}
		if(!flag){
			printf("-1\n");
			break;
		}
	}
	return 0;
}
