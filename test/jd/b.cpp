//
// Created by Leezed on 2025/8/16.
//
#include"bits/stdc++.h"

using namespace std;

// 用双向队列来维护 单调递增和单调递减

deque<long long> xiao, da;


void xiao_push(long long x) {
    while (!xiao.empty() && xiao.back() > x) {
        xiao.pop_back();
    }
    xiao.push_back(x);
}

void xiao_pop(long long x) {
    if (xiao.front() == x) {
        xiao.pop_front();
    }
}


void da_push(long long x) {
    while (!da.empty() && da.back() < x) {
        da.pop_back();
    }
    da.push_back(x);
}

void da_pop(long long x) {
    if (da.front() == x) {
        da.pop_front();
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    long long num[n];
    for (int i = 0; i < n; i += 1) {
        cin >> num[i];
    }
    long long sum = 0;
    long long max_res = 0;
    int ans = -1;
    for (int i = 0; i < m - 1; i += 1) {
        sum += num[i];
        xiao_push(num[i]);
        da_push(num[i]);
    }
    for (int i = m - 1; i < n; i += 1) {
        sum += num[i];
        xiao_push(num[i]);
        da_push(num[i]);

        long long res = sum - xiao.front() - da.front();
        int l = i - m + 1;
        if (res > max_res) {
            max_res = res;
            ans = l;
        }

        sum -= num[l];

        xiao_pop(num[l]);
        da_pop(num[l]);
    }
    cout << ans + 1 << endl;
    return 0;
}


/*
5 3
4 3 4 4 4

6 4
4 2 8 5 9 3



*/