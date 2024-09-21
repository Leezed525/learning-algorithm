//
// Created by Leezed on 2024/9/21.
//
#include<string>
#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 3e5;
int pos[maxn];
int abccount = 0;

int count_abc(string s) {
    //统计字符串中子串abc的个数
    for (int i = 0; i < s.length() - 2; i += 1) {
        if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
            abccount += 1;
            pos[abccount] = i;
        }
    }
    return abccount;
}

int bi_find_pos(int x) {
    //二分查找x在pos数组中的位置
    int l = 1, r = abccount;
    while (l < r) {
        int mid = (l + r) / 2;
        if (pos[mid] == x) {
            return mid;
        }
        if (pos[mid] < x) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    if (pos[l] != x) {
        return -1;
    }
}

int main() {
    int origin_len, q_num;
    cin >> origin_len >> q_num;
    string origin;
    cin >> origin;
    count_abc(origin);
    sort(pos + 1, pos + abccount + 1);
    while (q_num--) {
        int insert;
        char ch;
        cin >> insert >> ch;
        if (ch == origin[insert - 1]) {
            cout << abccount << endl;
            continue;
        }
        int index = bi_find_pos(insert - 1);

//        origin[insert - 1] = ch;
    }
    return 0;
}