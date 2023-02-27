#include <bits/stdc++.h>
using namespace std;
#define ms(x, n) memset(x, n, sizeof(x));
//*(int(*)[10])arr_name
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
inline int lowbit(int x) { return x & -x; }

string mingwPath = "";

// 获取必要参数
void getParamter() {
    printf("请输入你的mingw编译器的bin目录地址(按回车确定):\n");
    getline(cin, mingwPath);
    int len = mingwPath.length();
    // 替换所有'\' 变成 '/'
    for (int i = 0; i < len; i += 1) {
        if (mingwPath[i] == '\\') {
            mingwPath[i] = '/';
        }
    }
    cout << mingwPath << endl;
}

int main() {
    getParamter();
    // system("pause");
    return 0;
}