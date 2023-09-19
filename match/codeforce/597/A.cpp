#include <bits/stdc++.h>
using namespace std;

inline int gcd(int a,int b){
	return b ?gcd(b,a%b) :a;
}

int main(){
	int t,a,b;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a,&b);
		if(gcd(a,b) == 1) printf("Finite\n");
		else printf("Infinite\n");
	}
	return 0;
}
