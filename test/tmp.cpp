#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int divide(int a, int b) {
        bool neg_flag = true;
        if (a < 0) neg_flag = !neg_flag;
        if (b < 0) neg_flag = !neg_flag;

        unsigned _a = a < 0 ? ~a + 1U : a;
        unsigned _b = b < 0 ? ~b + 1U : b;
        unsigned res = 0;
        int pos = 31;

        while (_a >= _b) {
            unsigned tmp = _b;
            tmp = tmp << pos;
            cout << "tmp = " << tmp << endl;
            while (_a < (_b << pos)){
                pos--;
                cout << pos << endl;
            }
            _a -= (_b << pos);
            res |= (1 << pos);
        }

//        while (_a >= _b) {
//            while ((_a >> pos) < _b) pos--;
//            _a -= (_b << pos);
//            res |= (1U << pos);
//        }

        if (res > INT_MAX) {
            return neg_flag ? INT_MAX : INT_MIN;
        }

        return neg_flag ? res : -res;
    }
};

int main(){
    Solution s;
    cout << s.divide(15, 2) << endl;
    return 0;
}