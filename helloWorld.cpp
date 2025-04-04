#include "bits/stdc++.h"

using namespace std;

bool isInt(string s, bool allow_symbol = true) {
    //判断一个数是否是整数，只能包含数字和正负号
    //如果是空串，返回false
    if (s.size() == 0) return false;
    //判断首位后是否出现了正负号
    for (int i = 1; i < s.size(); i += 1) {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    if (s[0] == '+' || s[0] == '-') {
        if (!allow_symbol) return false;
        //如果首位是正负号
        if (s.size() == 1) return false;
        return true;
    } else return true;

    return false;
}

bool isDecimal(string s, int dot_pos) {
    int start = 0;
    string pre;
    if (s[0] == '+' || s[0] == '-')
        pre = s.substr(1, dot_pos - 1);
    else pre = s.substr(0, dot_pos);
    string post = s.substr(dot_pos + 1);
    if (pre.size() == 0) return isInt(post, false);
    if (post.size() == 0) return isInt(pre, true);
    else return isInt(pre, true) && isInt(post, false);

}


bool validNumber(string s) {
    //去除首尾空格
    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    //去除所有空格,以及排除掉不是数字的情况
    string str = "";
    //判断有没有e
    int e_num = 0;
    int e_index = -1;
    //判断是否有小数点
    int dot_num = 0;
    int dot_index = -2;
    for (char c: s) {
        str += c;
        if (c == 'e' || c == 'E') {
            e_num++;
            e_index = str.size() - 1;
        } else if (c == '.') {
            dot_num++;
            dot_index = str.size() - 1;
        } else if (c < '0' || c > '9') {
            //如果不是数字，返回false
            if (c != '+' && c != '-') return false;
        }
    }

    //判断e的个数
    if (e_num > 1 || dot_num > 1 || str.size() == 0) {
        return false;
    }
    if (e_num == 0) {
        //没有e的情况
        // 判断正负号出现的位置，如果
        if (dot_num == 0) {
            return isInt(str);
        } else { //只是一个简单的小数的情况
            return isDecimal(str, dot_index);
        }
    } else {
        if (dot_index > e_index) {
            //如果小数点在e的后面，返回false
            return false;
        }
        //判断e后面的数字是否是整数
        string pre = str.substr(0, e_index);
        string post = str.substr(e_index + 1);

//            cout << pre << " " << post << endl;
        if (dot_num == 1) {
            return isDecimal(pre, dot_index) && isInt(post);
        } else return isInt(pre, true) && isInt(post, true);
    }
    return true;
}

int main() {

    string s = "3.";
    validNumber(s) ? cout << "true" : cout << "false";

}
