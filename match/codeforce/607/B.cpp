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
const int MAXN = 5e3 + 5;
struct node{
	char ch;
	int pos;
}bj[MAXN];

int main()
{
	int T;
	cin >> T;
	while(T--){
		string s1,s2;
		cin >> s1 >> s2;
		int len1 = s1.length(),len2 = s2.length();
		bj[len1 - 1].ch = s1[len1 - 1];
		bj[len1 - 1].pos = len1 - 1;
		for(int i = len1 - 2;i >= 0;i--){
			if(s1[i] < bj[i+ 1].ch){
				bj[i].ch = s1[i];
				bj[i].pos = i;
			}
			else{
				bj[i] = bj[i + 1];
			}
		}
		if(s1 < s2){
			cout << s1 << endl;
			continue;
		}
		else{
			string tmp = s1;
			sort(tmp.begin(),tmp.end());
			int pos = -1;
			for(int i = 0;i < len1;i++){
				if(s1[i] != tmp[i]){
					pos = i;
					break;
				}
			}
			if(pos == -1){
				cout << "---" << endl;
			}
			else{
				for(int i = len1 - 1;i >= 0;i--){
					if(s1[i] == tmp[pos]){
						swap(s1[i],s1[pos]);
						if(s1 < s2)
							cout << s1 << endl;
						else
							cout << "---" <<endl;
						break;
					}
				}
			}
		}
	}
	return 0;
}

