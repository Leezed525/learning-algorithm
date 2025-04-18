//
// Created by Leezed on 2025/4/18.
//
#include "iostream"
#include "vector"


using namespace std;

int N, d;

const int maxn = 1e3 + 10;
vector<vector<int>> g(maxn, vector<int>());
int x[maxn] = {0};
int y[maxn] = {0};

int fa[maxn];


void init(int n) {
    for (int i = 0; i <= n; i += 1) {
        fa[i] = -1;
    }
}


int get(int t) {
    return fa[t] == t ? t : fa[t] = get(fa[t]);
}

void merge(int a, int b) {
    fa[get(a)] = get(b);
}


int main() {
    cin >> N >> d;
    init(N);
    for (int i = 1; i <= N; i += 1) {
        cin >> x[i] >> y[i];
        for (int j = 0; j < i; j += 1) {
            int x_len = x[i] - x[j];
            int y_len = y[i] - y[j];
            if (x_len * x_len + y_len * y_len <= d * d) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    char op;
    while (~scanf("%c", &op)) {
        cin >> op;
        if (op == 'O') {
            int num1;
            cin >> num1;
            fa[num1] = num1;
            for (int i = 0; i < g[num1].size(); i += 1) {
                int num2 = g[num1][i];
                if (fa[num2] != -1) {
                    merge(num1, num2);
                }
            }
        } else if (op == 'S') {
            int num1, num2;
            cin >> num1 >> num2;
            if(fa[num1] == -1 || fa[num2] == -1) {
                cout << "FAIL" << endl;
            } else {
                if (get(num1) == get(num2)) {
                    cout << "SUCCESS" << endl;
                } else {
                    cout << "FAIL" << endl;
                }
            }
        }
    }

    return 0;
}