#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b;
	cin >> a >> b;
	
	for(int i = b-a+1;i<=b+a-1;i++){
		printf("%d ",i);
	}
	printf("\n");
	return 0;
}
