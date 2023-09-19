#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#include<sstream>
using namespace std;
#define look(type,num,name) *(#type(*)[num])#name
typedef long long LL;
const int INF = 0x3f3f3f3f;

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0;i < n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	for(int i = 0;i < n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
/*
10
9 8 7 6 5 4 3 2 1  0
*/