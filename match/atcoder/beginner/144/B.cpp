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
	int a;
	double b;
	cin >> a;
	for(int i = 1;i <= 9;i++){
		for(int j = 1;j <= 9;j++){
			if(i * j == a){
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No");
	return 0;
}

