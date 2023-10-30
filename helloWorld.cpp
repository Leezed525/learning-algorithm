#include<bits/stdc++.h>

using namespace std;

int main() {
    int year, month;
    cin >> year >> month;
    if (year % 4 == 0 || year % 100 == 0 && month == 2) {
        cout << 29 << endl;
    } else {
        cout << 28 << endl;
    }
}