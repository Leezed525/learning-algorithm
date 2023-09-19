#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b;
	cin >>a >>b;
	int ans = 0;
	if(b == 1){
		printf("0\n");
		return 0;
	}
	for(int i = 1;i < 100;i++){
		if(a+(a-1) * (i - 1) >= b){
			cout << i << endl;
			break;
		}
	}
	return 0;
}
