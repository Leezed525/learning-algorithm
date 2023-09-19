#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    int count[26] = {0};
    for(char i :s) {
        count[i - 'a'] += 1;
    }
    int maxn = 0;
    int minn = 999;
    for(int i = 0 ;i < 26;i++) {
        if(count[i] > maxn) maxn = count[i];
        if(count[i] < minn && count[i] > 0) minn = count[i];
    }
    if(is_prime(maxn - minn)) {
        cout << "Lucky Word" << endl;
        cout << maxn - minn << endl;
    }else{
        cout << "No Answer"  << endl;
        cout << 0 << endl;
    }


    // system("pause");
    return 0;
}