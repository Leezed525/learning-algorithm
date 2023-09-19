#include<bits/stdc++.h>
using namespace std;
map<char,string>mp;
bool fg[27];
int main()
{
	string a1,a2,a3,ans;
	cin >> a1 >> a2 >> a3;
	if(a1 == "A" && a2 == "A" && a3 == "A"){
		cout << "Failed" << endl;
		return 0;
	}
	for(int i = 0;i < a1.length();i++){
		if(mp[a1[i]] == ""){
			mp[a1[i]] = a2[i];
			if(fg[a2[i] - 'A']){
				cout << "Failed" << endl;
				return 0;
			}
			fg[a2[i] - 'A'] = true;
		}
		else if(mp[a1[i]][0] != a2[i]){
			cout << "Failed" << endl;
			return 0;
		}
	}
	for(int i = 0;i < a3.length();i++){
		if(mp[a3[i]] != ""){
			ans += mp[a3[i]];
		}
		else{
			cout << "Failed" << endl;
			return 0;
		}
	}
	cout << ans << endl;
	return 0;
}
