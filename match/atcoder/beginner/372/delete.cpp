//
// Created by Leezed on 2024/9/21.
//
#include<string>
#include<iostream>
using namespace std;


int main(){
    string s;
    cin >> s;
    string ans = "";
    for (int i = 0; i < s.length(); i += 1) {
        if (s[i] != '.') {
            ans += s[i];
        }
    }
    cout << ans << endl;
    return 0;
}
