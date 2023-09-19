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
#define look(type,num,name) *(#type(*)[num])#name
using namespace std;
typedef long long LL;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
int maxn[MAXN],minn[MAXN],biaoji[MAXN];
int flag[MAXN];
int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        maxn[i] = -INF;
        minn[i] = INF;
    }
    for(int i = 0;i < n;i++){
        int num;
        scanf("%d",&num);
        int x,pre = -INF;
        for(int j = 0;j < num;j++){
            scanf("%d",&x);
            maxn[i] = max(maxn[i],x);
            minn[i] = min(minn[i],x);
            if(x > pre){
                flag[i]++;
            }
            pre = x;
        }
    }
    int tmp = 0;
    printf("look(int,10,biaoji)\n");
    for(int i = 0;i < n;i++){
        if(flag[i] <= 1){
            biaoji[tmp++] = maxn[i];
        }
    }
    sort(biaoji,biaoji + tmp);
    LL ans = 0;
    for(int i = 0;i < n;i++){
        if(flag[i] > 1){
            ans += n;
            continue;
        }
        int pos = upper_bound(biaoji,biaoji + tmp,minn[i]) - biaoji;
        ans += n - pos;
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}