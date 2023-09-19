#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2 * 1e5 + 5;
int n,r,q;
struct node{
	int id;
	long long point;
	int v;
}n1[MAXN];

bool cmp(node a,node b){
	if(a.point == b.point)
		return a.id < b.id;
	else
		return a.point > b.point;
}


void merge(node win[],node lose[])
{
	int t = 1,w = 1,l = 1;
	while(w <= n && l <= n){
		if(cmp(win[w],lose[l])){
			n1[t++] = win[w++];
		}
		else
			n1[t++] = lose[l++];
	}
	while(w <= n)	n1[t++] = win[w++];
	while(l <= n)	n1[t++] = lose[l++];
} 
int main()
{
	cin >> n >> r >> q;
	for(int i = 1;i <= 2 * n;i++){
		scanf("%d",&n1[i].point);
		n1[i].id = i;
	}
	for(int i = 1;i <= 2 * n;i++){
		scanf("%d",&n1[i].v);
	}
	sort(n1 + 1,n1 + 1 + 2 * n,cmp);
	for(int i = 1;i <= r;i++){
		node win[n + 1],lose[n + 1];
		int wl = 1,ll = 1;
		for(int j = 1;j <= n;j++){
			if(n1[2 * j - 1].v > n1[2 * j].v){
				n1[2 * j - 1].point++;
				win[wl++] = n1[2 * j - 1];
				lose[ll++] = n1[2 * j];
			}
			else{
				n1[2 * j].point++;
				lose[ll++] = n1[2 * j - 1];
				win[wl++] = n1[2 * j];
			}		
		}
		merge(win,lose);
	}
	//sort(n1 + 1,n1 + 1 + 2 * n,cmp);
	cout << n1[q].id << endl;
	return 0;
}
