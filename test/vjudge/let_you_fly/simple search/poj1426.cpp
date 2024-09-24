//
// Created by Leezed on 2024/9/20.
//
#include "string"
#include "iostream"
#include "cstring"
#include "queue"

using namespace std;
int mod[1000000];
string ans = "";

struct node {
    int num;
    string s;

    node(int num, string s) {
        this->num = num;
        this->s = s;
    }
};


int main() {
    int n;
    while (cin >> n && n != 0) {
//    for (int n = 1; n <= 210; n += 1) {
//        printf("n = %d, ans=", n);
        memset(mod, 0, sizeof(mod));
        queue<node> q;
        node head = node(1, "1");
        q.push(head);
        mod[1] = 1;
        while (!q.empty()) {
            node now = q.front();
            q.pop();
            int x = now.num;
            if ((x * 10 + 1) % n == 0) {
                cout << now.s + "1" << endl;
                break;
            } else {
                int tmp = (x * 10 + 1) % n;
                if (mod[tmp] != 1) {
                    mod[tmp] = 1;
                    q.push(node(tmp, now.s + "1"));
                }
            }
            if ((x * 10) % n == 0) {
                cout << now.s + "0" << endl;
                break;
            } else {
                int tmp = (x * 10) % n;
                if (mod[tmp] != 1) {
                    mod[tmp] = 1;
                    q.push(node(tmp, now.s + "0"));
                }
            }
        }
    }

//    }
    return 0;
}