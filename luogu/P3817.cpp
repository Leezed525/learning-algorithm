#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    int a[n + 1] = {0};
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] + a[i + 1] > x) {
            int diff = a[i] + a[i + 1] - x;
            ans += diff;
            if (a[i + 1] > diff) {
                a[i + 1] -= diff;
            } else {
                a[i + 1] = 0;
            }
        }
    }
    cout << ans << endl;
    // system("pause");
    return 0;
}