#include<bits/stdc++.h>
using namespace std;


int main()
{
	int a,b;
	cin >> a >> b;
	int maxn = a+b;
	if(a-b>maxn)maxn = a-b;
	if(a*b>maxn)maxn = a*b;
	printf("%d\n",maxn);
	return 0;
} 
