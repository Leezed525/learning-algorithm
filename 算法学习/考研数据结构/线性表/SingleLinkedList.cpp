#include<bits/stdc++.h>

using namespace std;
//*(int(*)[10])arr_name
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);

inline int lowbit(int x) { return x & -x; }

typedef struct Lnode {
    int data;
    struct Lnode *next;
} Lnode, *LinkedList;

/**
 * @brief 创建一个单链表
 * @param head
 */
void initList(LinkedList &head) {
    head = (LinkedList) malloc(sizeof(Lnode));
    head->data = 0;
    head->next = NULL;
}

/**
 * @brief 头插法创建一个单链表
 * @param head
 */
void headInsertList(LinkedList &head) {
    int data[10] = {5, 1, 3, 4, 2, 7, 0, 9, 8, 6};
    int i = 0;
    Lnode *tmp;
    while (i < 10) {
        tmp = (Lnode *) malloc(sizeof(Lnode));
        tmp->data = data[i];
        tmp->next = head->next;
        head->next = tmp;
        i += 1;
    }
}

/**
 * @brief 尾插法创建一个单链表
 * @param head
 */
void tailInsertList(LinkedList &head) {
    int data[10] = {5, 1, 3, 4, 2, 7, 0, 9, 8, 6};
    int i = 0;
    Lnode *tmp;
    LinkedList tail = head;
    while (i < 10) {
        tmp = (Lnode *) malloc(sizeof(Lnode));
        tmp->data = data[i];
        tmp->next = NULL;
        tail->next = tmp;
        tail = tmp;
        i += 1;
    }
}

/**
 * 获取链表的长度
 * @param head
 * @return
 */
int getLength(LinkedList head){
    int len = 0;
    while (head) {
        head = head->next;
        len += 1;
    }
    return len;
}


bool isEmpty(LinkedList head){
    return head->next == nullptr;
}

/**
 * 打印链表
 * @param head
 */
void printList(LinkedList head) {
    cout << "当前链表为: ";
    head = head->next;
    int len = 0;
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
        len += 1;
    }
    printf("链表长度为%d \n", len);
}

/**
 * @brief 删除整个单链表
 * @param head
 */
void freeList(LinkedList &head) {
    int i = 0;
    while (head) {
        Lnode *tmp = head;
        head = head->next;
        free(tmp);
        i += 1;
    }
    cout << i << endl;
}

/**
 * 获取链表中的第 i 位
 *
 * @param head 链表
 * @param order  次序
 * @return
 */
Lnode *getNodeByOrder(LinkedList head, int order) {
    if (order < 1) {
        return nullptr;
    }
    int i = 0;
    while (head && i < order) {
        head = head->next;
        i += 1;
    }
    return head;
}

/**
 * 查找链表中值为e的节点
 * @param head
 * @param e
 * @return
 */
Lnode *getNodeByData(LinkedList head, int e){
    head = head->next;
    while (head) {
        if (head->data == e) {
            return head;
        }
        head = head->next;
    }
    //没找到，head为null
    return head;
}

/**
 * 在第 order位插入data的数据
 * @param head
 * @param order
 * @param data
 * @return bool
 */
bool insertAfterOrder(LinkedList &head, int order, int data) {
    Lnode *tmp = getNodeByOrder(head, order - 1);
    if (tmp == nullptr) {
        return false;
    }
    Lnode *p = (Lnode *) malloc(sizeof(Lnode *));
    p->next = tmp->next;
    p->data = data;
    tmp->next = p;
    return true;
}

/**
 * 删除第 order 位的节点
 * @param head
 * @param order
 * @return
 */
bool deleteNodeByOrder(LinkedList &head, int order){
    Lnode *pre = getNodeByOrder(head, order - 1);
    if (pre == nullptr) {
        return false;
    }
    Lnode *current = pre->next;
    pre->next = current->next;
    free(current);
    return true;
}

int main() {
    LinkedList head;
    initList(head);
    // 头插法
    cout << "头插法" << endl;
    headInsertList(head);
    printList(head);
    freeList(head);
    // 尾插法
    cout << "尾插法" << endl;
    initList(head);
    tailInsertList(head);
    printList(head);

    //获取链表的第3位
    cout << "获取链表的第3位" << endl;
    Lnode p = *getNodeByOrder(head, 3);
    cout << p.data << endl;
    printList(head);

    //获取链表中值为6的节点
    cout << "获取链表中值为6的节点" << endl;
    Lnode tmp = *getNodeByData(head, 6);
    cout << tmp.data << endl;

    //在第0位插入数据，失败
    cout << "在第0位插入数据" << endl;
    if(insertAfterOrder(head, 0, 11)) {
        cout << "插入成功" << endl;
        printList(head);
    } else {
        cout << "插入失败" << endl;
    }

    //在第5位插入数据，成功
    cout << "在第5位插入数据" << endl;
    if(insertAfterOrder(head, 5, 11)) {
        cout << "插入成功" << endl;
        printList(head);
    } else {
        cout << "插入失败" << endl;
    }

    //再第13位插入数据，失败
    cout << "在第13位插入数据" << endl;
    if(insertAfterOrder(head, 13, 11)) {
        cout << "插入成功" << endl;
        printList(head);
    } else {
        cout << "插入失败" << endl;
    }

    //删除第7为元素
    cout << "删除第七位元素" << endl;
    if(deleteNodeByOrder(head, 7)) {
        cout << "删除成功" << endl;
        printList(head);
    } else {
        cout << "删除失败" << endl;
    }
    return 0;
}