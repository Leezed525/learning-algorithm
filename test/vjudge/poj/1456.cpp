//
// Created by Leezed on 2025/3/14.
//
#include<iostream>
#include "stdio.h"
#include<algorithm>


using namespace std;


struct node {
    int profit;
    int deadline;
};

const int maxn = 1e5 + 10;

node nodes[maxn];

bool cmp(node a, node b) {
    return a.profit > b.profit;
}

int fa[maxn];


void init(int n) {
    for (int i = 0; i <= n; i += 1) {
        fa[i] = i;
    }
}

int get(int x) {
    if (x == fa[x]) return x;
    return fa[x] = get(fa[x]);
}

void merge(int x, int y) {
    fa[get(x)] = fa[get(y)];
}


int main() {

    int n;
    while (cin >> n) {
        int max_deadline = 0;
        for (int i = 0; i < n; i += 1) {
            scanf(" %d %d", &nodes[i].profit, &nodes[i].deadline);
            max_deadline = max(max_deadline, nodes[i].deadline);
        }

        init(max_deadline);

        sort(nodes, nodes + n, cmp);

        int res = 0;

        for (int i = 0; i < n; i += 1) {
            int d = get(nodes[i].deadline);
            if (d > 0) {
                res += nodes[i].profit;
//                cout << "+ " << nodes[i].profit  << endl;
                merge(d, d - 1);
            }
//            cout << nodes[i].profit << " " << nodes[i].deadline << endl;
        }

        cout << res << endl;
    }


    return 0;
}
