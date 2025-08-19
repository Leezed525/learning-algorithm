//
// Created by Leezed on 2025/8/19.
//
#include "bits/stdc++.h"

using namespace std;


const int maxn = 1e5 + 10;

long long num[maxn];

long long mod = 1e9 + 7;
int main() {

    int T;
    cin >> T;
    while (T--) {
        long long n, a, b;
        cin >> a >> b >> n;
        num[0] = 2;
        num[1] = a;
        for (int i = 2; i <= n; i += 1) {
            num[i] = (a * num[i - 1] % mod - b * num[i - 2] % mod + mod) % mod;
        }

        cout << num[n] << endl;
    }


    return 0;
}