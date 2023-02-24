#include <bits/stdc++.h>
using namespace std;

int main() {
    int count;
    cin >> count;
    while (count--) {
        int num;
        cin >> num;
        num--;
        int sum = 0;
        while (num--) {
            int vCount;
            cin >> vCount;
            int min1 = 10001, min2 = 10002;
            while (vCount--) {
                int x;
                cin >> x;
                if (x < min1) {
                    min2 = min1;
                    min1 = x;
                } else if (x < min2) {
                    min2 = x;
                }
            }
            sum += min1 + min2;
        }
        cout << sum << endl;
    }
    // system("pause");
    return 0;
}