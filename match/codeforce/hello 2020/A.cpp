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

int main()
{
    long long n,m;
    cin >> n >> m;
    string s1[n],s2[m];
    for(int i = 0;i < n;i++){
        cin >> s1[i];
    }
    for(int i = 0;i < m;i++){
        cin >> s2[i];
    }
    int num = 0;
    cin >> num;
    while(num--){
        int nn;
        scanf("%d",&nn);
        cout << s1[(nn - 1) % n] << s2[(nn - 1) % m] << endl;
    }
    return 0;
}