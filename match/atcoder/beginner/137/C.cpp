#include<bits/stdc++.h>
using namespace std;

int main()
{
	map<string,int>m;
	int n,sum=0;
	cin >> n;
	while(n--){
		char a[11];
		string s1;
		cin >>a;
		sort(a,a+10);
		for(int i = 0;i <10;i++){
			s1+=a[i];
		}
		m[s1]++;
	}
	map<string,int>::iterator it;
	for(it = m.begin();it!=m.end();it++){
		for(int i = 1;i <= it -> second-1;i++){
			sum+=i;
		}
	}
	printf("%d\n",sum);
	return 0;
}
