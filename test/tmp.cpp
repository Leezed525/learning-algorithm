#include<bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, x, m = 1;
        cin >> n;
        string s = "";
        while (m <= n) {
            cout << "? " << s << "0" << endl;
            cin >> x;
            if (x) {
                s += "0";
                ++m;
                continue;
            }
            cout << "? " << s << "1" << endl;
            cin >> x;
            if (!x)break;
            s += "1";
            ++m;
        }
        while (m <= n) {
            cout << "? 0" << s << endl;
            cin >> x;
            if (x) {
                s = "0" + s;
                ++m;
                continue;
            }
            s = "1" + s;
            ++m;
        }
        cout << "! " << s << endl;
    }
    return 0;
}