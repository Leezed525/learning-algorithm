//
// Created by Leezed on 2022/7/19.
// 顺序表
//
#include<bits/stdc++.h>

using namespace std;
const int maxSize = 20 + 5;


typedef struct {
    int data[maxSize];
    int length;
} OList;


void printList(OList list) {
    for (int i = 0; i < list.length; i += 1) {
        printf("%d ", list.data[i]);
    }
    printf("\n");
}

void clearOrderList(OList &list) {
    memset(list.data, 0, sizeof(list.data));
    list.length = 0;
}

bool initOrderList(OList &list, int data[],int len) {
    if (len > maxSize) {
        return false;
    }
    for (int i = 0; i < len; i += 1) {
        list.data[i] = data[i];
    }
    list.length = len;
}


bool insertOrderList(OList &list, int order, int data) {
    if (order > list.length + 1 || order <= 0) {
        return false;
    }
    if (list.length == maxSize) {
        return false;
    }

}


int main() {

    OList list;
    clearOrderList(list);

    int initData[] = {7, 2, 5, 4, 5};
    initOrderList(list, initData,5);
    printList(list);
    system("pause");
    return 0;
}
