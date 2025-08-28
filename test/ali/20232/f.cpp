//
// Created by Leezed on 2025/8/26.
//
#include "bits/stdc++.h"

using namespace std;

const int maxn = 1e5 + 10;

int a[maxn];

int main() {


    int n;
    cin >> n;
    for (int i = 0; i < n; i += 1) {
        cin >> a[i];
    }
    sort(a, a + n);
    vector<int> ans;
    int left = 0, right = n - 1;
    while (left < right) {
        ans.push_back(a[left]);
        ans.push_back(a[right]);
        left++;
        right--;
    }
    if (left == right) {
        ans.push_back(a[left]);
    }
    long long res = 0;
    for (int i = 1; i < n; i += 1) {
        res += abs(ans[i] - ans[i - 1]);
    }
    res += abs(ans[0] - ans[n - 1]);
    cout << res << endl;
    for (int i = 0; i < n; i += 1) {
        cout << ans[i] << (i == n - 1 ? '\n' : ' ');
    }
    return 0;
}