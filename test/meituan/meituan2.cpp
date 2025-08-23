//
// Created by Leezed on 2025/8/23.
//
#include "bits/stdc++.h"

using namespace std;

int vector_to_number(const vector<int> &vec) {
    int res = 0;
    for (int i = 0; i < vec.size(); i++) {
        res = res * 2 + vec[i];
    }
    return res;
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        stack<int> st;
        int n;
        cin >> n;
        int x = n;
        while (x > 0) {
            st.push(x % 2);
            x /= 2;
        }
        int len = st.size();
        vector<int> tmp(20, 0);
        for (int i = 20 - len; i < 20; i += 1) {
            tmp[i] = st.top();
            st.pop();
        }
        set<int> s;
        s.insert(vector_to_number(tmp));
        for (int i = 0; i < 20; i += 1) {
            if (tmp[i] == 0) {
                tmp[i] = 1;
                s.insert(vector_to_number(tmp));
                tmp[i] = 0;
            }
        }
        cout << s.size() << endl;
        for (auto a: s) {
            cout << a << " ";
        }
        cout << endl;
    }
}