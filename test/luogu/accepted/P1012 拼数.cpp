#include<bits/stdc++.h>
using namespace std;
bool cmp(string a,string b)
{
	return a + b > b + a; 
}
int main()
{
	string a[21];
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	sort(a,a + n,cmp);
	for(int i = 0;i < n;i++){
		cout << a[i];
	}
	cout << endl;
	return 0;
}
