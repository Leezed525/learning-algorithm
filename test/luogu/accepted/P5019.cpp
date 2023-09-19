#include <bits/stdc++.h>
using namespace std;
int a[100010];
int ans = 0;

void fun(int l,int r){
    if(l > r){
        return ;
    }
    if(l == r){
        ans += a[l];
        a[l] = 0;
        return ;
    }
    int minn = 100000;
    int index = 0;
    for(int i = l;i <= r;i++){
        if(minn > a[i]){
            minn = a[i];
            index = i;
        }
    }
    ans += minn;
    for(int i = l;i <= r;i++){
        a[i] -= minn;
    }
    fun(l,index -1 );
    fun(index + 1,r);;

}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    
    fun(1,n);
    cout << ans << endl;

    // system("pause");
    return 0;
}