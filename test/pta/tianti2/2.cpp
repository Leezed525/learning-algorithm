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

int main() {
    int h, m;
    scanf("%d:%d", &h, &m);
    if (m > 0) h++;
    if (h <= 12)
        printf("Only %02d:%02d.  Too early to Dang.\n", h - (m > 0 ? 1 : 0), m);
    else
        for (int i = 1; i <= h - 12; i++) printf("Dang");
    // system("pause");
    return 0;
}