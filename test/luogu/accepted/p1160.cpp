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
struct node{
    int pre;
    int next;
}a[MAXN];

int main()
{
    int n,head = 1;
    cin >> n;
    for(int i = 2;i <= n;i++){
        int x,pos;
        scanf("%d%d",&x,&pos);
        if(x == head && pos == 0){
            head = i;
        }
        if(pos == 0){
            a[i].pre = a[x].pre;
            a[a[x].pre].next = i;
            a[x].pre = i;
            a[i].next = x; 
        }
        else if(pos == 1){
            a[i].next = a[x].next;
            a[a[x].next].pre = i;
            a[x].next = i;
            a[i].pre = x;
        }
    }
    int m;
    cin >> m;
    for(int i = 0;i < m;i++){
        int x;
        scanf("%d",&x);
        if(a[x].pre == -1)
            continue;
        if(x == head){
            head = a[x].next;
        }
        a[a[x].pre].next = a[x].next;
        a[a[x].next].pre = a[x].pre;
        a[x].pre = -1;
        a[x].next = -1;
    }
    for(int i = head;i != 0;i = a[i].next){
        if(i != head){
            printf(" ");
        }
        printf("%d",i);
    }
    cout << endl;
    return 0;
}