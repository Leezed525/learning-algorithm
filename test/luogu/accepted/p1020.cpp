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
const int MAXN = 1e5 + 5;
int a[MAXN];
int l[MAXN];
int f[MAXN];
int main()
{
    int num = 1;
    int x;
    while(~scanf("%d",&x)){
        a[num++] = x;
    }
    //n2做法
    // int maxn = 0;
    // for(int i = 1;i < num;i++){
    //     for(int j = 0;j < i;j++){
    //         f[i] = max(f[i],f[j] +(a[i] < a[j]?1:0));
    //         maxn = max(maxn,f[i]);
    //     }
    // }
    // cout << maxn - 1 << endl;
    //2log2n做法
    int lenl = 1,lenf = 1;
    l[1] = f[1] = a[1];
    for(int i = 2;i < num;i++){
        if(a[i] <= f[lenf]){
            f[++lenf] = a[i];
        }
        else{
            *upper_bound(f + 1,f + 1 + lenf,a[i],greater<int>()) = a[i];
        }
        if(a[i] > l[lenl]){
            l[++lenl] = a[i];
        }
        else{
            *lower_bound(l + 1,l + 1 + lenl,a[i]) = a[i];
        }
    }
    cout << lenf << endl <<lenl << endl;
    //system("pause");
    return 0;
}