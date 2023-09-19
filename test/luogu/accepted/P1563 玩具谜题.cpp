#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5; 
struct ps{
	string name;
	int face;
}person[MAXN];

int main()
{
	int m,n;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> person[i].face >> person[i].name;
	}
	int zhi = 0;
	for(int i = 0;i < m;i++){
		int dir,length;
		cin >> dir >> length;
		if(person[zhi].face == 0){
			if(dir == 0){
				zhi-=length%n;
				if(zhi < 0)
					zhi+=n;
				
			}
			else{
				zhi+=length%n;
				if(zhi>=n)
					zhi-=n;
			}
		}
		else{
			if(dir == 0){
				zhi+=length%n;
				if(zhi>=n)
					zhi-=n;
			}
			else{
				zhi-=length%n;
				if(zhi < 0)
					zhi+=n;
			}
		}
	}
	cout << person[zhi].name <<endl;
	return 0;
}
