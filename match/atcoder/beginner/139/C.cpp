#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;
const int inf = 0x3f3f3f3f;
int a[MAXN];
int dp[MAXN];
int main()
{
	int n;
	cin >> n;
	int maxlen = -1*inf ,len = 0;
	int t = inf;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		if(a[i] <= t){
			t = a[i];
			len++;
			if(len > maxlen) maxlen = len;
		}
		else{
			t = a[i]; 
			len = 1;
		}
	}
	cout << maxlen- 1 << endl;
	return 0;
}
