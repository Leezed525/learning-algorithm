#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[100];
    cin.getline(s, 100);
    int ans = 0;
    for (char i : s) {
        if (i == '\0') {
            break;
        }
        if (i != ' ') {
            ans += 1;
        }
    }
    cout << ans << endl;

    // system("pause");
    return 0;
}