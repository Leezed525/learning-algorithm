#include "bits/stdc++.h"

using namespace std;


map<pair<int, int>, bool> m;

int main() {


    //写入文件
    string train_file = "train.txt";
    string val_file = "val.txt";
    string test_file = "test.txt";


    int train_num = 40000;
    int val_num = 10000;
    int test_num = 10000;

    //生成训练集 随机两个数的异或

    freopen(train_file.c_str(), "w", stdout);
    srand(time(0));

    for (int i = 0; i < train_num; i += 1) {
        //随机生成1 - 30000 之间的两个数
        int a = rand() % 30000 + 1;
        int b = rand() % 30000 + 1;
        pair<int, int> p = make_pair(a, b);
        if (m[p]) {
            i--;
            continue;
        }
        cout << a << " " << b << " " << (a ^ b) << endl;
    }

    //生成验证集

    freopen(val_file.c_str(), "w", stdout);
    srand(time(0));

    for (int i = 0; i < val_num; i += 1) {
        //随机生成1 - 30000 之间的两个数
        int a = rand() % 30000 + 1;
        int b = rand() % 30000 + 1;
        pair<int, int> p = make_pair(a, b);
        if (m[p]) {
            i--;
            continue;
        }
        cout << a << " " << b << " " << (a ^ b) << endl;
    }

    //生成测试集

    freopen(test_file.c_str(), "w", stdout);
    srand(time(0));

    for (int i = 0; i < test_num; i += 1) {
        //随机生成1 - 30000 之间的两个数
        int a = rand() % 30000 + 1;
        int b = rand() % 30000 + 1;
        pair<int, int> p = make_pair(a, b);
        if (m[p]) {
            i--;
            continue;
        }
        cout << a << " " << b << " " << (a ^ b) << endl;
    }
    return 0;
}
