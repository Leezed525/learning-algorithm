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
#define look(type,num,name) *(type(*)[num])name
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MAXN = 1500 + 5;
string s[MAXN];
int biaoji[MAXN][MAXN];
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> s[i];
    }
    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            for(int k = 0;k < m;k++){
                if(s[i][k] != s[j][k]){
                    biaoji[i][j]++;
                }
            }
            biaoji[j][i] = biaoji[i][j];
        }
    }
    long long ans = 0;
    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            if((m-biaoji[i][j]) % 2 == 0){
                for(int k = j + 1;k < n;k++){
                    if(biaoji[i][j] == biaoji[j][k] && biaoji[i][j] == biaoji[i][k]){
                        ans++;
                    }
                }
            }
        }
    } 
    printf("%d",ans);
    system("pause");
    return 0;
}