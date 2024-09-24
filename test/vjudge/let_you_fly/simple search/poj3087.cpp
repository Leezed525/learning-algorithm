//
// Created by Leezed on 2024/9/24.
//
#include "iostream"
#include "string"
#include "map"

using namespace std;

string shuffle(string s1, string s2, int len) {
    string tmp = "";
    for (int i = 0; i < len; i++) {
        tmp += s2[i];
        tmp += s1[i];
    }
    return tmp;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int len;
        cin >> len;
        string s1, s2, result, tmp;
        map<string, bool> m;
        cin >> s1 >> s2 >> result;
        cout << t << " ";
        tmp = shuffle(s1, s2, len);
        int count = 1;
        while (tmp.compare(result) != 0) {
            if (m[tmp]) {
                count = -1;
                cout << -1 << endl;
                break;
            }
            count++;
            m[tmp] = true;
            s1 = tmp.substr(0, len);
            s2 = tmp.substr(len);
            tmp = shuffle(s1, s2, len);
        }
        if (count != -1) {
            cout << count << endl;
        }


    }

    return 0;
}