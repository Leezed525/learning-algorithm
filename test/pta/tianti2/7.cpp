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
int gn, pn, ln, tn;
int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'G' || s[i] == 'g')
            gn++;
        else if (s[i] == 'P' || s[i] == 'p')
            pn++;
        else if (s[i] == 'L' || s[i] == 'l')
            ln++;
        else if (s[i] == 'T' || s[i] == 't')
            tn++;
    }
    while (gn > 0 || pn > 0 || ln > 0 || tn > 0) {
        if (gn > 0) {
            printf("G");
            gn--;
        }
        if (pn > 0) {
            printf("P");
            pn--;
        }
        if (ln > 0) {
            printf("L");
            ln--;
        }
        if (tn > 0) {
            printf("T");
            tn--;
        }
    }
    // system("pause");
    return 0;
}