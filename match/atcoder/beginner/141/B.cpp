#include<bits/stdc++.h>
using namespace std;

bool pan1(char ch)
{
	if(ch == 'R' || ch == 'U' ||ch == 'D')
		return false;
	return true;
}
bool pan2(char ch)
{
	if(ch == 'L' || ch == 'U' ||ch == 'D')
		return false;
	return true;
}

int main()
{
	string s;
	cin >> s;
	for(int i = 0;i < s.length();i++){
		if(i%2 == 0){
			if(s[i] == 'L'){
				cout << "NO" <<endl;
				return 0;
			}
				
		}
		else
			if(s[i] == 'R'){
				cout << "NO" <<endl;
				return 0;
			}
				
	}
	cout << "YES" << endl;
	return 0;
}
