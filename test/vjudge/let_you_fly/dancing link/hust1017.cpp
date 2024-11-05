//
// Created by Leezed on 2024/11/5.
// copy from https://blog.csdn.net/constbh/article/details/77891472
//
#include "iostream"
#include "string"

using namespace std;

const int MAXN = 1e3 + 5;
const int MAXP = 1e5 + 5 + MAXN;

struct DLX {
    int n, m, si;//n行m列,si代表节点数
    /*
     * 十字链表组成部分
     * up,down,left,right分别代表第i个节点上下左右四个方向的指针
     * Row[i]代表第i个节点所在的行号
     * Col[i]代表第i个节点所在的列号
     */
    int U[MAXP], D[MAXP], L[MAXP], R[MAXP], Row[MAXP], Col[MAXP];
    //h记录行的选择情况，s表示列的覆盖情况
    int H[MAXN], S[MAXN];
    //ansd记录答案的深度，ans记录答案
    int ansd, ans[MAXN];

    void init(int _n, int _m) {
        n = _n;
        m = _m;
        for (int i = 0; i <= m; i += 1) {
            S[i] = 0;
            //纵向链表为空(指向自己)
            U[i] = D[i] = i;
            //初始化横向链表
            L[i] = i - 1;
            R[i] = i + 1;
        }
        // 使其循环
        R[m] = 0;
        L[0] = m;
        // 目前初始化了m个节点 (因为输入的1的个数 >= m)
        si = m;
        for (int i = 1; i <= n; i += 1) {
            H[i] = -1;
        }
    }

    void link(int r, int c) {
        si++;
        // 记录当前点的列
        Col[si] = c;
        //当前列多了个1
        S[c]++;
        // 记录当前点的行
        Row[si] = r;
        // 更新首尾指针指向
        D[si] = D[c];
        U[D[c]] = si;
        U[si] = c;
        D[c] = si;
        if (H[r] < 0) { //横向链表还没有插入过值的情况
            H[r] = L[si] = R[si] = si; // 创建自循环节点
        } else {
            //将当前节点插入头结点后面，并更新左右指针(因为输入的时候是按照顺序输入的，所以相当于尾插法)
            R[si] = R[H[r]];
            L[R[H[r]]] = si;
            L[si] = H[r];
            R[H[r]] = si;
        }
    }

    void remove(int c) { //从列表中删除c列
        L[R[c]] = L[c]; //表头操作
        R[L[c]] = R[c];
        for (int i = D[c]; i != c; i = D[i]) {
            for (int j = R[i]; j != i; j = R[j]) {
                U[D[j]] = U[j];
                D[U[j]] = D[j];
                --S[Col[j]]; //当前列所含的1数量减1
            }
        }
    }

    void resume(int c) {//恢复c列
        for (int i = U[c]; i != c; i = U[i])
            for (int j = L[i]; j != i; j = L[j])
                ++S[Col[U[D[j]] = D[U[j]] = j]];
        L[R[c]] = R[L[c]] = c;
    }

    bool dance(int d) //选取了d行
    {
        if (R[0] == 0)//全部覆盖了
        {
            //全覆盖了之后的操作
            ansd = d;
            return true;
        }
        int c = R[0];
        for (int i = R[0]; i != 0; i = R[i])
            if (S[i] < S[c])
                c = i;
        remove(c);
        for (int i = D[c]; i != c; i = D[i]) {
            ans[d] = Row[i];
            for (int j = R[i]; j != i; j = R[j])
                remove(Col[j]);
            if (dance(d + 1))
                return true;
            for (int j = L[i]; j != i; j = L[j])
                resume(Col[j]);
        }
        resume(c);
        return false;
    }
} dlx;


int main() {
    int n, m;
    while (cin >> n >> m) {
        dlx.init(n, m);
        for (int i = 1; i <= n; i += 1) {
            int k;
            cin >> k;
            while (k--) {
                int tmp;
                cin >> tmp;
                dlx.link(i, tmp);
            }
        }
        dlx.ansd = -1;
        if (dlx.dance(0)) {
            cout << dlx.ansd ;
            for (int i = 0; i < dlx.ansd; ++i) {
                cout << " " << dlx.ans[i];
            }
            cout << endl;
        } else {
            printf("NO");
        }
    }
    return 0;
}