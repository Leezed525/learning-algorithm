//
// Created by Leezed on 2025/3/22.
// 手写堆

#include "bits/stdc++.h"

using namespace std;


struct heap {
    vector<int> q;
    int size = 0;

    //建堆
    void build(vector<int> &nums) {
        q = vector<int>(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) q[i + 1] = nums[i];
        size = nums.size();
        for (int i = size / 2; i >= 1; i--) heapify(i);
    }

    //插入堆
    void push(int x) {
        if (size == q.size() - 1) q.push_back(x);
        else q[size + 1] = x;
        size++;
        up(size);
    }

    void pop() {
        q[1] = q[size--];
        heapify(1);
    }

    int top() {
        return q[1];
    }

    //维护堆
    void heapify(int x) {
        int l = x * 2, r = x * 2 + 1, m = x;
        //小根堆
        if (l <= size && q[l] < q[m]) m = l;
        if (r <= size && q[r] < q[m]) m = r;
        if (m != x) {
            swap(q[m], q[x]);
            heapify(m);
        }
    }

    //上浮
    void up(int x) {
        while (x > 1 && q[x] < q[x / 2]) {
            swap(q[x], q[x / 2]);
            x /= 2;
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    }

}


int main() {

    return 0;
}