#include<bits/stdc++.h>
using namespace std;
const int MAXN = 20+5;
string s[MAXN];
int biaoji[MAXN];
int maxn = 0;
int n;

void dfs(string a,int len)
{
	if(len > maxn)
		maxn = len;
	for(int i = 1;i <= n;i++){
		if(biaoji[i] < 2 && a == s[i].substr(0,a.length())){
			biaoji[i]++;
			for(int j = 1;j < s[i].length();j++){
				dfs(s[i].substr(s[i].length() - j,j),len + s[i].length() - a.length());	
			}
			biaoji[i]--;
		}
	}
}
int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> s[i];
	}
	string ch;
	cin >> ch;
	dfs(ch,1);
	cout << maxn << endl;
}
