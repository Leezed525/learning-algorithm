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
int a[26][26];

int main()
{
	int T;
	cin >> T;
	while(T--){
		int n;
		scanf("%d",&n);
		string s1,s2;
		cin >> s1 >> s2;
		int flag = 0;
		memset(a,0,sizeof(a));
		int sum = 0;
		for(int i = 0;i < n;i++){
			if(s1[i] != s2[i]){
				a[s1[i] - 'a'][s2[i] - 'a']++;
			}
		}
		for(int i = 0;i < 26;i++){
			for(int j = 0;j < 26;j++){
				if(a[i][j] % 2 == 1){
					flag = 1;
					break;
				}
				else if(a[i][j] > 0){
					if(sum < 1){
						sum++;
					}
					else{
						flag = 1;
						break;
					}
				}
			}
			if(flag == 1)
				break;
		}
		if(flag)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}

