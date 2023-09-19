#include<bits/stdc++.h>
using namespace std;
int M;
const int N = 1e5+5;
int ans[N];
int getnum(char x)
{
	if(x >= '0' && x <= '9')
		return x - '0';
	else if(x >= 'A' && x <= 'Z')
		return x - 'A' + 10;
	else if(x >= 'a' && x <= 'z')
		return x - 'a' + 10;
	return -1;
}

void init(string x)
{
	int n = 1;
	for(int i = 0;i < x.length();i++){
		ans[n++] = getnum(x[i]);
	}
	ans[0] = n-1;
}

bool pan()
{
	int n = ans[0];
	for(int i = 1;i <= n/2;i++){
		if(ans[i]!=ans[n+1-i])return false;
	}
	return true;
}

void add()
{
	int n = ans[0];
	for(int i = 1;i <=n/2;i++){
		int  t = ans[n - i+1];
		ans[n-i+1] += ans[i];
		ans[i] += t;
	}
	if(n % 2 == 1){
		ans[n/2+1] += ans[n/2+1];
	}
	
	for(int i = 1;i <=n;i++){
		if(ans[i] >= M){
			if(i == n){
				n++;
				ans[n] += ans[i] / M;
				ans[i] = ans[i] % M;
			}
			ans[i+1] += ans[i]/M;
			ans[i] = ans[i]%M;
		}
	}
	ans[0] = n;
}

int main()
{
	string n;
	cin >> M >> n;
	init(n);
	int flag = 0;
	for(int i = 0;i <30;i++){
		if(pan()){
			flag = i;
			break;
		}
		add();
	}
	if(flag == 0)
		printf("Impossible\n");
	else
		cout << "STEP=" << flag << endl;
}
