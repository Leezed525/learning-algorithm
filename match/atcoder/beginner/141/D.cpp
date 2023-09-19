#include<bits/stdc++.h>
using namespace std;

int main()
{
	priority_queue <int,vector<int>,less<int> >q;
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		int t;
		scanf("%d",&t);
		q.push(t);
	} 
	for(int i = 0;i < m;i++){
		int t = q.top();
		q.pop();
		t /= 2;
		q.push(t);
	}
	long long sum = 0;
	while(!q.empty()){
		sum += q.top();
		q.pop();
	}
	cout << sum << endl;
	return 0;
}
