#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        char ch;
        cin >> a >> ch >> b;
        // cout << a << ch << b << endl;
        if (ch == '+') {
            cout << a + b << endl;
        } else if (ch == '-') {
            cout << a - b << endl;
        } else if (ch == '*') {
            cout << a * b << endl;
        }
    }

    // system("pause");
    return 0;
}