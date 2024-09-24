//
// Created by Leezed on 2024/9/20.
//
#include<bits/stdc++.h>

using namespace std;

int main() {
    int num;
    cin >> num;
    while (num--) {
        int n;
        int x, y;
        cin >> n >> x >> y;
        if (n % min(x, y) == 0) {
            printf("%d\n", n / min(x, y));
        } else {
            printf("%d\n", n / min(x, y) + 1);
        }
    }
    return 0;
}