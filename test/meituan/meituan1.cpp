//
// Created by Leezed on 2025/8/23.
//
#include "bits/stdc++.h"


using namespace std;


int main() {
    int n, m;

    cin >> n >> m;
    long long ans = 0;
    for (int i = 0; i < n; i += 1) {
        long long a, b;
        cin >> a >> b;
        long long max_side = max(a, b);
        long long min_side = min(a, b);
        if (max_side > m) {
            ans += max_side;
        } else {
            ans += min_side;
        }
    }
    cout << ans << endl;
}
