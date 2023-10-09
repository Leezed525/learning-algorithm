//
// Created by Leezed on 2023/10/8.
//
#include<iostream>
#include<cstring>
using namespace std;
int T;
int n;
int main(){
    cin >> T;
    while (T--) {
        cin >> n;
        int ans = 0;
        for (int i = 1; i < n; i += 1) {
            int x;
            cin >> x;
            ans += x;
        }
        cout << -ans<< endl;
    }
    return 0;

}
