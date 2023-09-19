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
int biaoji[3];

int main()
{
	int n;
	int num = 2;
	while(num--)
	{
		cin >> n;
		biaoji[n - 1] = 1;
	}
	for(int i = 0;i < 3;i++){
		if(biaoji[i] == 0){
			cout << i +1 << endl;
			break;
		}
			
	}
	return 0;
}

