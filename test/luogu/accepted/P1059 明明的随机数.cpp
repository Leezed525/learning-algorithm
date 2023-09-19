#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	set<int>s;
	for(int i = 0;i < n;i++){
		int t;
		scanf("%d",&t);
		s.insert(t);
	}
	printf("%d\n",s.size());
	set<int>::iterator it;
	for(it = s.begin();it != s.end();it++){
		cout << *it << " ";
	}
	return 0;
} 
