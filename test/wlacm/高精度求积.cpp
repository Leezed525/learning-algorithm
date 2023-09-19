#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+6;
int main()
{
	string x,y;
	cin >> x >> y;
	if(x == "0" || y == "0"){
		printf("0\n");
		return 0;
	}
	int len1 = x.length();
	int len2 = y.length();
	
	int ans[N] = {0};
	//cout << x << endl << y << endl;
	for(int i = 0;i < len1;i++){
		for(int j = 0;j < len2 ;j++){
			ans[len2+len1 - i - j] += (x[i] - '0') * (y[j] - '0'); 
		}	
	}	
	for(int i = 2;i <=len1 + len2;i++){
		if(i == len1+len2){
			break;
		}
		if(ans[i] >= 10){
			ans[i+1] += ans[i] / 10;
			ans[i] = ans[i] % 10;
		}
	}
	for(int i = len1+len2;i >=2;i--){
		printf("%d",ans[i]);
	}
	return 0;
}
