#include<bits/stdc++.h>
using namespace std;
int sum,nn=0;
struct point{
	int day,reward;
	
}n1[100000];

bool cmp(point a,point b){
	if(a.day!=b.day) return a.day>b.day;
	else return a.reward > b.reward;
}

int main()
{
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		if(a > m )continue;
		else {
			n1[nn].day = a;
			n1[nn++].reward = b;
		}
	}
	sort(n1,n1+nn,cmp);
	for(int i = 0;i<nn;i++){
		printf("%d %d\n",n1[i].day,n1[i].reward);
	}
}
