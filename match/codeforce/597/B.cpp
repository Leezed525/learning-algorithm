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
const int MAXN = 1e2+5;
char ans[MAXN];
int R,P,S;
int fg[MAXN],n;

void init()
{
	R = P = S = 0; 
	for(int i = 0;i < MAXN ;i++){
		ans[i] = ' ';
	}
}

int main()
{
	int T;
	cin >> T;
	while(T--){
		init();
		scanf("%d",&n);
		scanf("%d %d %d",&R,&P,&S);
		string s;
		cin >> s;
		int sum = 0;
		for(int i = 0;i < n;i++){
			if(s[i] == 'R' && P > 0){
				ans[i] = 'P';
				P--;
				sum++;
			}
			else if(s[i] == 'P' && S > 0){
				ans[i] = 'S';
				S--;
				sum++;
			}
			else if(s[i] == 'S' && R > 0){
				ans[i] = 'R';
				R--;
				sum++;
			}
		}
		if(sum >= (n + 1) / 2){
			printf("YES\n");
			for(int i = 0;i < n;i++){
				if(ans[i] != ' ')
					printf("%c",ans[i]);
				else{
					if(R > 0){
						printf("R");
						R--;
					}
					else if(P > 0){
						printf("P");
						P--;
					}
					else if(S > 0){
						printf("S");
						S--;
					}
				}	
			}
			printf("\n");
		}
		else
			printf("NO\n");
	}
	return 0;
}

