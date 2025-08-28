//
// Created by Leezed on 2025/8/26.
//
#include "bits/stdc++.h"

using namespace std;

int main() {

    int A, B, a, b;
    cin >> A >> B >> a >> b;

    int tmp = __gcd(a, b);
    a /= tmp;
    b /= tmp;

    int a_res = A / a;
    int b_res = B / b;
    int min_res = min(a_res, b_res);
    if (min_res == 0) {
        cout << 0 << " " << 0 << endl;
    } else {
        cout << min_res * a << " " << min_res * b << endl;
    }
    return 0;
}