#include <bits/stdc++.h>
using namespace std;

struct node {
    int index;
    int num;
    bool exist;
};
bool cmp(node a, node b) {
    if (a.num == b.num) return a.index < b.index;
    return a.num > b.num;
}
bool cmp1(node a, node b) { return a.index < b.index; }

int find_next(node a[], int j, int len) {
    for (int i = j + 1; i < len + 1; i++) {
        if (a[i].exist) {
            return i;
        }
    }
}

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    int len = s.length();
    node a[len + 1];
    for (int i = 0; i < len; i++) {
        a[i].num = s[i] - '0';
        a[i].index = i;
        a[i].exist = true;
    }
    a[len].num = 0;
    a[len].exist = true;
    // sort(a, a + len, cmp);
    // for (int i = 0; i < len; i++) {
    //     cout << a[i].num << ' ' << a[i].index << endl;
    // }
    for (int i = 0; i < k; i += 1) {
        for (int j = 0; j < len; j += 1) {
            if (a[j].exist == false) {
                continue;
            }
            if (a[j].num > a[find_next(a, j, len)].num) {
                a[j].exist = false;
                break;
            }
        }
    }
    sort(a, a + len, cmp1);
    bool zeroFlag = true;
    bool outputFlag = false;
    for (int i = 0; i < len; i += 1) {
        if (a[i].exist) {
            if (a[i].num != 0) {
                zeroFlag = false;
            } else {
                if (zeroFlag) continue;
            }
            printf("%d", a[i].num);
            outputFlag = true;
        }
    }
    if(!outputFlag){
        cout << 0 << endl;
    }
    cout << endl;

    // system("pause");
    return 0;
}