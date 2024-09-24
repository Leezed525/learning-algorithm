//
// Created by Leezed on 2024/9/20.
//
#include "bits/stdc++.h"

using namespace std;

int main() {
    int num;
    cin >> num;

    while (num--) {
        int n;
        cin >> n;
        long long a[n];
        for (long long i = 0; i < n; i += 1) {
            cin >> a[i];
        }
        long long base = a[n - 2];

        for (long long i = n - 3; i >= 0; i -= 1) {
            base -= a[i];
        }
        cout << a[n - 1] - base << endl;
    }
    return 0;
}