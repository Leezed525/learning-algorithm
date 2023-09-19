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
//*(int(*)[10])arr_name
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 5;
bool prime[MAXN];
int sum[MAXN];
void shai()
{
    memset(prime,true,sizeof(prime));
    prime[0] = prime[1] = false;
    sum[0] = sum[1] = 0;
    for(int i = 2;i <= 1e6;i++){
        if(prime[i] == true){
            for(int j = 2 * i;j <= 1e6;j += i){
                prime[j] = false;
            }
            sum[i] = sum[i - 1] + 1;
        }
        else{
            sum[i] = sum[i - 1];
        }
    }
}
int main()
{
    int T,m;
    shai();
    cin >> T >> m;
    while(T--){
        int l,r;
        scanf("%d%d",&l,&r);
        if(l < 1 || r > m){
            cout << "Crossing the line" << endl;
        }
        else
            cout << sum[r] - sum[l - 1] << endl;
    }
    //system("pause");
    return 0;
}