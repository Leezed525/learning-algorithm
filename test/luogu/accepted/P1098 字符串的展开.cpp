#include<bits/stdc++.h>
using namespace std;

bool pan(char a,char b)
{
	if(b >= '0' && b <= '9' && a >= '0' && a <= '9')
		return false;
	else if(b >= 'a' && b <= 'z' && a >= 'a' && a <= 'z')
		return false;
	return true;
}

int main()
{
	int p1,p2,p3;
	cin >> p1 >> p2 >> p3;
	string s1;
	cin >> s1;
	string ans;
	int lens1 = s1.length();
	for(int i = 0;i < lens1;i++){
		if(s1[i] == '-'){
			if(s1[i + 1] <= s1[i - 1])
				ans += s1[i];
			else if(s1[i + 1] - s1[i - 1] == 1)
				continue;
			else if(pan(s1[i - 1],s1[i + 1]))
				ans += s1[i];
			else if(s1[i + 1] - s1[i - 1] > 1){
				if(p3 == 2){
					stack<char>s;
					for(char k = s1[i - 1] + 1;k < s1[i + 1];k++){
						char ch = k;
						if(p1 == 1){
							if(ch >= 'A' && ch <= 'Z')
								ch += 32;
							for(int j = 0;j < p2;j++)
								s.push(ch);
						}
						else if(p1 == 2){
							if(ch >= 'a' && ch <= 'z')
								ch -= 32;
							for(int j = 0;j < p2;j++)
								s.push(ch);		
						}
						else{
							for(int j = 0;j < p2 ;j++){
								s.push('*');
							}
						}
					}
					while(!s.empty()){
						char ch = s.top();
						ans += ch;
						s.pop();
					}
				}
				else{
					for(char k = s1[i - 1] + 1;k < s1[i + 1];k++){
						char ch = k;
						if(p1 == 1){
							if(ch >= 'A' && ch <= 'Z')
								ch += 32;
							for(int j = 0;j < p2;j++)
								ans += ch;
						}
						else if(p1 == 2){
							if(ch >= 'a' && ch <= 'z')
								ch -= 32;
							for(int j = 0;j < p2;j++)
								ans+=ch;	
						}
						else{
							for(int j = 0;j < p2 ;j++){
								ans+='*';
							}
						}
					}
				}
			}
		}
		else
			ans += s1[i];
	}
	cout << ans << endl;
	return 0;
} 
