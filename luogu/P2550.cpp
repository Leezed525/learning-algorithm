#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans[8];
    for (int i = 0; i <= 8; i += 1) {
        ans[i] = 0;
    }
    int b[50];
    for (int i = 0; i <= 50; i += 1) {
        b[i] = 0;
    }
    for (int i = 0; i < 7; i++) {
        int x;
        cin >> x;
        b[x] = 1;
    }
    while (n--) {
        int tmp = 0;
        for (int i = 0; i < 7; i++) {
            int x;
            cin >> x;
            if (b[x] == 1) {
                tmp += 1;
            }
        }
        ans[tmp] += 1;
    }
    for (int i = 7; i >= 1; i--) {
        printf("%d ",ans[i]);
    }

    // system("pause");
    return 0;
}