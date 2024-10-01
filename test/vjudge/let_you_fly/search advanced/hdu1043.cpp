//
// Created by Leezed on 2024/9/26.
//
#include "iostream"
#include "cstring"
#include "queue"
#include "unordered_map"

using namespace std;


string END = "12345678x";
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dirs[] = {'l', 'r', 'u', 'd'};
unordered_map<string, string> d;

void bfs() {
    queue<string> q;
    q.push(END);
    d[END] = "";
    while (!q.empty()) {
        string front = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int zero = front.find('x');
            int x = zero / 3;
            int y = zero % 3;
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                string new_front = front;
                swap(new_front[x * 3 + y], new_front[nx * 3 + ny]);
                if (d.count(new_front) == 0) {
                    d[new_front] = d[front] + dirs[i];
                    q.push(new_front);
                }
            }
        }
    }

}

int main() {
    bfs();
    string s = "";
    char tmp;
    while (cin >> tmp) {
        s += tmp;
        for (int i = 1; i < 9; i += 1) {
            cin >> tmp;
            s += tmp;
        }
//        cout << s << endl;
        if (d.count(s) == 0) {
            cout << "unsolvable" << endl;
        } else {
            string ans = d[s];
            for (int i = ans.size() - 1; i >= 0; i -= 1) {
                cout << ans[i];
            }
            cout << endl;
        }
        s = "";
    }
    return 0;
}
