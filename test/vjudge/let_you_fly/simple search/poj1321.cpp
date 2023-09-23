//
// Created by Leezed on 2023/9/23.
//
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int MAX_N = 10;
int mp[MAX_N][MAX_N];
//代表这一列是否被占用
bool column[MAX_N];
int ans = 0;
int n = -1, k = -1;


void init() {
    memset(mp, 0, sizeof(mp));
    ans = 0;
}

void print_map(int n) {
    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= n; j += 1) {
            printf("%d ", mp[i][j]);
        }
        printf("\n");
    }
}

/**
 * 深度优先搜索
 * @param current_row 当前搜索所在行数
 * @param last_item 现在还差多少颗棋子没放
 */
void dfs(int current_row, int last_item) {
    if (last_item == 0) {
        ans += 1;
        return;
    }
    // 如果当前行数大于n，那么就不可能放下了
    if (current_row > n) return;
    // 如果剩余的棋子数大于当前行数，那么就不可能放下了
    if (n - current_row + 1 < last_item) return;
    // 考虑当前行不放子的情况
    dfs(current_row + 1, last_item);
    for (int i = 1; i <= n; i += 1) {
        // 如果当前列已经被占用，那么就不能放了
        if (column[i]) continue;
        // 如果当前位置不能放，那么就不能放了
        if (mp[current_row][i] == 0) continue;
        // 如果当前位置可以放，那么就放下
        column[i] = true;
        dfs(current_row + 1, last_item - 1);
        column[i] = false;
    }

}


int main() {

    while (cin >> n >> k) {
        if (n == -1 && k == -1) break;
        init();
        for (int i = 1; i <= n; i += 1) {
            for (int j = 1; j <= n; j += 1) {
                char tmp;
                scanf("%c", &tmp);
                if (tmp == '\n') scanf("%c", &tmp);
                if (tmp == '.') mp[i][j] = 0;
                else mp[i][j] = 1;
            }
        }
        dfs(1, k);
        cout << ans << endl;
//        printf("\n");
//        print_map(n);
    }
    return 0;
}