#include<bits/stdc++.h>
using namespace std;
int biao[5][5] = {{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
int main()
{
	int n,az,bz;
	cin >> n >> az >> bz;
	int a[az],b[bz];
	for(int i = 1;i < az;i++)	scanf("%d",&a[i]);
	scanf("%d",&a[0]);
	for(int i = 1;i < bz;i++)	scanf("%d",&b[i]); 
	scanf("%d",&b[0]);
	int ascore = 0,bscore = 0;
	for(int i = 1;i <= n;i++){
		ascore += biao[a[i%az]][b[i%bz]];
		bscore += biao[b[i%bz]][a[i%az]];
	}
	cout << ascore << " " << bscore << endl;
	return 0;
}
