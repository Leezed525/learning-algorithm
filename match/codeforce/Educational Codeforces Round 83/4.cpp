#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 7;
const double pi = acos(-1);
const int mod = 998244353;
int a[10];

int main(){
	int cnt = 0;
	for(int i = 1;i <= 7;i++){
		for(int j = 1;j <= 7;j++){
			for(int k = 1;k <= 7;k++){
				for(int l = 1;l <= 7;l++){
					a[1] = i; a[2] = j; a[3] = k; a[4] = l;
					if(a[1] == a[3] || a[2] == a[4] || a[1] == a[4]){
						if(a[1]!=a[2]&&a[2]!=a[3]&&a[3]!=a[4]){
							if((a[1]<a[2]&&a[2]>a[3]&&a[3]>a[4]) || (a[1]<a[2]&&a[2]<a[3]&&a[3]>a[4])){
								cout << a[1] << " " << a[2] << " " << a[3] <<" " <<a[4]<< endl;
								cnt++;
							}
						}
					}
				}
			}
		}
	}
	cout << cnt<< endl;
	return 0;
}