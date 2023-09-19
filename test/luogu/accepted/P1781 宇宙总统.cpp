#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string maxn;
	int id;
	for(int i = 1;i <= n;i++){
		string s;
		cin >> s;
		if(s.length() > maxn.length()){
			id = i;
			maxn = s;
		}
		else if(s.length() == maxn.length()){
			if(s > maxn){
				id = i;
				maxn = s;
			}
		}
	}
	cout << id << endl << maxn << endl;
}
