#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
//*(int(*)[10])arr_name
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);

int pan(string s) {
    int num = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9')
            num = num * 10 + s[i] - '0';
        else
            return -1;
    }
    if (num > 1000 || num <= 0) return -1;
    return num;
}

int main() {
    string a, b;
    getline(cin,a);
	b=a;
	b.erase(0, b.find_first_of(" ")+1);
	a.erase(a.find_first_of(" ")); 
    int a1 = pan(a);
    int b1 = pan(b);
    if (a1 == -1)
        printf("? ");
    else
        printf("%d ", a1);
    printf("+ ");
    if (b1 == -1)
        printf("? ");
    else
        printf("%d ", b1);
    printf("= ");
    if (a1 != -1 && b1 != -1)
        printf("%d", a1 + b1);
    else
        printf("?");
    // system("pause");
    return 0;
}