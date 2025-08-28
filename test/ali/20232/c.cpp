//
// Created by Leezed on 2025/8/26.
//
#include "bits/stdc++.h"

using namespace std;

const int maxn = 1e5 + 10;

int a[maxn];

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i += 1) {
            cin >> a[i];
        }
        if(n == 1){
            cout << a[0] << endl;
            continue;
        }
        sort(a, a + n);
        int ans = 0;
        for (int i = n - 1; i != 1; i -= 2) { // 剩余两人时退出循环
            if (i == 2) {
                ans += a[0] + a[i];//若剩下最轻的三人a<=b<=c，a载c过去，再还船回来，此时也剩下ab两人
                break;
            }
            ans += min(2 * a[1], a[0] + a[i - 1]) + a[0] + a[i];
            // 若剩下有大于等于四个人，运两个人过去耗费的时间=min(a+2*b+d,2*a+c+d)
        }
        cout << ans + a[1] << endl;

    }

    return 0;

}