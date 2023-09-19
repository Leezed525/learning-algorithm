#include <bits/stdc++.h>
using namespace std;

int main() {
    int l, m;
    cin >> l >> m;
    bool a[l + 1];
    for (int i = 0; i <= l; i += 1) {
        a[i] = true;
    }
    while (m--) {
        int c, b;
        cin >> c >> b;
        for (int i = c; i <= b; i += 1) {
            a[i] = false;
        }
    }
    int ans = 0;
    for (int i = 0; i <= l; i += 1) {
        if (a[i]) {
            ans += 1;
        }
    }
    cout << ans << endl;
    // system("pause");
    return 0;
}