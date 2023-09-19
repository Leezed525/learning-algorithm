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

struct node{
	int val,id;
};

bool cmp(node a,node b){
	if(a.val == b.val)
		return a.id < b.id;
	else
		return a.val < b.val;
}

int main()
{
	int T;
	cin >> T;
	while(T--){
		int n,m;
		cin >> n >> m;
		node a[n];
		int sum = 0;
		for(int i = 0;i < n;i++){
			scanf("%d",&a[i].val);
			a[i].id = i + 1;
			sum += a[i].val;
		}
		if(m < n || n <= 2)
			cout << -1 << endl;
		else{
			sum *= 2;
			sort(a,a+n,cmp);
			m -= n;
			sum += (a[0].val + a[1].val) * m; 
			printf("%d\n",sum);
			for(int i = 1;i <= n;i++){
				if(i == n)
					printf("%d %d\n",i,1);
				else
					printf("%d %d\n",i,i + 1);
			}
			
			for(int i = 0;i < m;i++){
				printf("%d %d\n",a[0].id,a[1].id);
			}
		}
	}
	return 0;
}

