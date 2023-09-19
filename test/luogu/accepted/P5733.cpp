#include <bits/stdc++.h>
using namespace std;

char getUpper(char c) { return (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c; }

int main() {
    string s;
    cin >> s;
    for(char i :s){
        printf("%c", getUpper(i));
    }

    // system("pause");
    return 0;
}