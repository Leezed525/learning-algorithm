#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;

bool cmp(string a,string b)
{
	return a < b;
}
int main()
{
	mp["zero"] = "00";
	mp["one"] = "01";
	mp["two"] = "04";
	mp["three"] = "09";
	mp["four"] = "16";
	mp["five"] = "25";
	mp["six"] = "36";
	mp["seven"] = "49";
	mp["eight"] = "64";
	mp["nine"] = "81";
	mp["ten"] = "00";
	mp["eleven"] = "21";
	mp["twelve"] = "44";
	mp["thirteen"] = "69";
	mp["fourteen"] = "96";
	mp["fifteen"] = "25";
	mp["sixteen"] = "56";
	mp["seventeen"] = "89";
	mp["eighteen"] = "24";
	mp["nineteen"] = "61";
	mp["twenty"] = "00";
	mp["a"] = "01";
	mp["both"] = "04";
	mp["another"] = "01";
	mp["first"] = "01";
	mp["second"] = "04";
	mp["third"] = "09";
	string s,a[100],tmp;
	getline(cin,s);
	s = " " + s;
	int flag = 0,t = 0;
	for(int i = 0;i < s.length();i++){
		if(s[i] == ' '){
			a[t++] = mp[tmp];
			tmp.clear();
		}
		else{
			tmp += s[i];
		}
	}
	sort(a,a+t,cmp);
	string ans;
	for(int i = 0;i < t;i++)
		ans += a[i];
	if(ans == ""){
		printf("0\n");
		return 0;
	}
	for(int i = 0;i < ans.length();i++){
		if(flag == 0 && ans[i] == '0')
			continue;
		else{
			flag = 1;
			printf("%c",ans[i]);
		}
	}
	return 0;
} 
