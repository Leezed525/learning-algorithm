#include <bits/stdc++.h>
using namespace std;

int main() {
    int w, x, h;
    cin >> w >> x >> h;
    int q;
    cin >> q;
    bool a[w + 1][x + 1][h + 1];
    for (int i = 0; i <= w; i += 1) {
        for (int j = 0; j <= x; j += 1) {
            for (int k = 0; k <= h; k += 1) {
                a[i][j][k] = true;
            }
        }
    }
    while (q--) {
        int x1, x2, y1, y2, z1, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for (int i = x1; i <= x2; i += 1) {
            for (int j = y1; j <= y2; j += 1) {
                for (int k = z1; k <= z2; k += 1) {
                    a[i][j][k] = false;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= w; i += 1) {
        for (int j = 1; j <= x; j += 1) {
            for (int k = 1; k <= h; k += 1) {
                if (a[i][j][k]) {
                    ans += 1;
                }
            }
        }
    }
    cout << ans << endl;
    // system("pause");
    return 0;
}