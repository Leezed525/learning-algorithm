#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool flag[2000000 + 10] = {0};
    while (n--) {
        double a;
        int t;
        cin >> a >> t;
        for (int i = 1; i <= t; i += 1) {
            int num = (int)(i * a);
            flag[num] = !flag[num];
        }
    }
    for (int i = 1;; i += 1) {
        if (flag[i]) {
            cout << i << endl;
            return 0;
        }
    }
    // system("pause");
    return 0;
}