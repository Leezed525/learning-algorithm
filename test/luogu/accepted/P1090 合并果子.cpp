#include<bits/stdc++.h>
using namespace std;

int main()
{
	priority_queue<int,vector<int>,greater<int> >q;
	int n;
	cin >> n;
	long long sum = 0;
	for(int i = 0;i < n;i++){
		int t;
		scanf("%d",&t);
		q.push(t);
	}
	while(q.size() > 1){
		int a1 = q.top();
		q.pop();
		int a2 = q.top();
		q.pop();
		sum += a1 + a2;
		q.push(a1+a2);
	}
	cout << sum << endl;
	return 0;
}
