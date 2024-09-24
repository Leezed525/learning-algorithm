//
// Created by Leezed on 2024/9/24.
//
#include "iostream"
#include "string"
#include "map"
#include "queue"
#include "stack"

using namespace std;


struct op {
    int a; //操作代码，1 fill ,2 drop, 3 pour
    int num1, num2;

    op() : a(0), num1(0), num2(0) {}

    op(int a, int num1, int num2) : a(a), num1(num1), num2(num2) {}
};

struct status {
    pair<int, int> now;
    op last;

    status() : now(make_pair(0, 0)), last(op(0, 0, 0)) {}

    status(pair<int, int> now, op last) : now(now), last(last) {}
};

////用于追踪key这个节点是使用了什么方法过来的
//map<pair<int, int>, op> m;
////判断是否存在过的map 同时key 是子，value是父，用于追踪输出路径
//map<pair<int, int>, pair<int, int>> dad_m;

map<pair<int, int>, status> m;


void print_path(pair<int, int> now) {
    stack<string> s;
    while (now.first != 0 || now.second != 0) {
        status last = m[now];
        op tmp = last.last;
        if (tmp.a == 1) {
            if (tmp.num1 == 1) {
                s.push("FILL(1)");
            } else {
                s.push("FILL(2)");
            }
        } else if (tmp.a == 2) {
            if (tmp.num1 == 1) {
                s.push("DROP(1)");
            } else {
                s.push("DROP(2)");
            }
        } else {
            if (tmp.num1 == 1) {
                s.push("POUR(1,2)");
            } else {
                s.push("POUR(2,1)");
            }
        }
        now = last.now;
    }
    cout << s.size() << endl;
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
}


int main() {
    int a, b, c;
    cin >> a >> b >> c;
    m.clear();
    queue<pair<int, int>> q;

    pair<int, int> start = make_pair(0, 0);
    q.push(start);
    m[start] = status(start, op(0, 0, 0));
    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();
        if (now.first == c || now.second == c) {
            print_path(now);
            return 0;
        }
        //fill 1
        if (now.first < a) {
            pair<int, int> next = make_pair(a, now.second);
            if (m.count(next) == 0) {
                op tmp = op(1, 1, 0);
                m[next] = status(now, tmp);
                q.push(next);
            }
        }
        // fill 2
        if (now.second < b) {
            pair<int, int> next = make_pair(now.first, b);
            if (m.count(next) == 0) {
                op tmp = op(1, 2, 0);
                m[next] = status(now, tmp);
                q.push(next);
            }
        }

        //drop 1
        if (now.first > 0) {
            pair<int, int> next = make_pair(0, now.second);
            if (m.count(next) == 0) {
                op tmp = op(2, 1, 0);
                m[next] = status(now, tmp);
                q.push(next);
            }
        }

        // drop 2
        if (now.second > 0) {
            pair<int, int> next = make_pair(now.first, 0);
            if (m.count(next) == 0) {
                op tmp = op(2, 2, 0);
                m[next] = status(now, tmp);
                q.push(next);
            }
        }

        //pour 1,2
        if (now.first > 0 && now.second < b) {
            int pour = min(now.first, b - now.second);
            pair<int, int> next = make_pair(now.first - pour, now.second + pour);
            if (m.count(next) == 0) {
                op tmp = op(3, 1, 2);
                m[next] = status(now, tmp);
                q.push(next);
            }
        }

        //pour 2,1
        if (now.second > 0 && now.first < a) {
            int pour = min(now.second, a - now.first);
            pair<int, int> next = make_pair(now.first + pour, now.second - pour);
            if (m.count(next) == 0) {
                op tmp = op(3, 2, 1);
                m[next] = status(now, tmp);
                q.push(next);
            }
        }
    }

    cout << "impossible" << endl;


    return 0;
}