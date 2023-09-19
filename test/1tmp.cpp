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
#define ms(x, n) memset(x, n, sizeof(x));
using namespace std;
//*(int(*)[10])arr_name
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
inline int lowbit(int x) { return x & -x; }

const int maxn = 10 + 5;

struct node {
    string name;
    int age;
};

struct orderNode{
    int *data;
    int length;
};

//初始化顺序表
void initOrderNode(orderNode &o, int maxSize){
    o.data = (int *) malloc(sizeof(int) * maxSize);
    for(int i = 0;i < maxSize;i++){
        o.data[i] = 0;
    }
    o.length = 0;
}

//push
void pushOrderNode(orderNode &l, int x){
    l.data[l.length++] = x;
}

void printOrderNode(orderNode &l){
    for(int i = 0;i < l.length;i++){
        cout << l.data[i] << " ";
    }
    cout << endl;
}

void reverseOrderNode(orderNode &l){
    for(int i = 0;i < l.length / 2 ;i++){
        swap(l.data[i], l.data[l.length - i - 1]);
    }
}


int main() {
    orderNode l;
    initOrderNode(l, maxn);
    pushOrderNode(l, 1);
    pushOrderNode(l, 2);
    pushOrderNode(l, 3);
    pushOrderNode(l, 4);
    pushOrderNode(l, 5);
    pushOrderNode(l, 6);
    system("pause");
    return 0;
}