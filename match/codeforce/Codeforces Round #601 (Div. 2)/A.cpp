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
	int T;
	cin >> T;
	while(T--){
		int a,b;
		cin >> a >> b;
		int num = abs(a - b);
		if(num % 5 == 0){
			cout << num / 5 << endl;
		}
		else if(num % 5 <= 2){
			cout << num / 5 + 1 << endl;
		} 
		else if(num % 5 == 3){
			cout << num / 5 + 2 << endl;
		}
		else
			cout << num / 5 + 2 << endl;
	} 
	return 0;
}

