//
// Created by Leezed on 2023/10/8.
//
#include "iostream"
#include "cstring"

#include "algorithm"

using namespace std;
const int maxn = 1e5 + 10;

struct node {
    long long a, cost;

    node(long long a, long long cost) : a(a), cost(cost) {}

    node() {}
};


node resident[maxn];

bool cmp(node a, node b) {
    if (a.cost == b.cost)
        return a.a < b.a;
    return a.cost < b.cost;
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        long long n, p;
        cin >> n >> p;
        for (int i = 1; i <= n; i += 1) {
            scanf("%lld", &resident[i].a);
        }
        for (int i = 1; i <= n; i += 1) {
            scanf("%lld", &resident[i].cost);
        }
        sort(resident + 1, resident + n + 1, cmp);
        long long last = n - 1;
        long long sumcost = 0;
        sumcost += p;
        for (int i = 1; i <= n; i += 1) {
            if (last == 0) {
                break;
            }
            if (p < resident[i].cost) {
                sumcost += p * last;
                last = 0;
                break;
            }
            if (resident[i].a > last) {
                sumcost += resident[i].cost * last;
                last = 0;
                break;
            } else {
                sumcost += resident[i].cost * resident[i].a;
                last -= resident[i].a;
            }
        }
        cout << sumcost << endl;
//        for (int i = 1; i <= n; i += 1) {
//            cout << resident[i].a << " " << resident[i].cost << endl;
//        }

    }
}