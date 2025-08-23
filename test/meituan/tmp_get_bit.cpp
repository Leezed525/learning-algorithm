//
// Created by Leezed on 2025/8/23.
//
#include "bits/stdc++.h"

using namespace std;

int main() {
    int x;
    cin >> x;
    stack<int> st;
    while (x > 0) {
        st.push(x % 2);
        x /= 2;
    }
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}
