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
typedef long long LL;
const int INF = 0x3f3f3f3f;


int main()
{
	int n;
	cin >> n;
	int a[n + 2],bj1[n + 2],bj2[n + 2];
	for(int i = 0;i < n;i++){
		scanf("%d",&a[i]);
	}
	bj1[0] = 1;
	int maxn = -INF;
	for(int i = 1;i < n;i++){
		if(a[i] > a[i - 1])
			bj1[i] = bj1[i - 1] + 1;
		else
			bj1[i] = 1;
		maxn = max(maxn,bj1[i]);
	}
	bj2[n - 1] = 1;
	for(int i = n - 2;i >= 0;i--){
		if(a[i] < a[i + 1])
			bj2[i] = bj2[i + 1] + 1;
		else
			bj2[i] = 1;
	}
	
	for(int i = 0;i < n - 2;i++){
		if(a[i] < a[i + 2])
			maxn = max(maxn,bj1[i] + bj2[i + 2]);
	}
	cout << maxn << endl;
	return 0;
}

