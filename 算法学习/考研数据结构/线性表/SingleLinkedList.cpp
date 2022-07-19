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
 * @brief ����һ��������
 * @param head
 */
void initList(LinkedList &head) {
    head = (LinkedList) malloc(sizeof(Lnode));
    head->data = 0;
    head->next = NULL;
}

/**
 * @brief ͷ�巨����һ��������
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
 * @brief β�巨����һ��������
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
 * ��ȡ����ĳ���
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
 * ��ӡ����
 * @param head
 */
void printList(LinkedList head) {
    cout << "��ǰ����Ϊ: ";
    head = head->next;
    int len = 0;
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
        len += 1;
    }
    printf("������Ϊ%d \n", len);
}

/**
 * @brief ɾ������������
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
 * ��ȡ�����еĵ� i λ
 *
 * @param head ����
 * @param order  ����
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
 * ����������ֵΪe�Ľڵ�
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
    //û�ҵ���headΪnull
    return head;
}

/**
 * �ڵ� orderλ����data������
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
 * ɾ���� order λ�Ľڵ�
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
    // ͷ�巨
    cout << "ͷ�巨" << endl;
    headInsertList(head);
    printList(head);
    freeList(head);
    // β�巨
    cout << "β�巨" << endl;
    initList(head);
    tailInsertList(head);
    printList(head);

    //��ȡ����ĵ�3λ
    cout << "��ȡ����ĵ�3λ" << endl;
    Lnode p = *getNodeByOrder(head, 3);
    cout << p.data << endl;
    printList(head);

    //��ȡ������ֵΪ6�Ľڵ�
    cout << "��ȡ������ֵΪ6�Ľڵ�" << endl;
    Lnode tmp = *getNodeByData(head, 6);
    cout << tmp.data << endl;

    //�ڵ�0λ�������ݣ�ʧ��
    cout << "�ڵ�0λ��������" << endl;
    if(insertAfterOrder(head, 0, 11)) {
        cout << "����ɹ�" << endl;
        printList(head);
    } else {
        cout << "����ʧ��" << endl;
    }

    //�ڵ�5λ�������ݣ��ɹ�
    cout << "�ڵ�5λ��������" << endl;
    if(insertAfterOrder(head, 5, 11)) {
        cout << "����ɹ�" << endl;
        printList(head);
    } else {
        cout << "����ʧ��" << endl;
    }

    //�ٵ�13λ�������ݣ�ʧ��
    cout << "�ڵ�13λ��������" << endl;
    if(insertAfterOrder(head, 13, 11)) {
        cout << "����ɹ�" << endl;
        printList(head);
    } else {
        cout << "����ʧ��" << endl;
    }

    //ɾ����7ΪԪ��
    cout << "ɾ������λԪ��" << endl;
    if(deleteNodeByOrder(head, 7)) {
        cout << "ɾ���ɹ�" << endl;
        printList(head);
    } else {
        cout << "ɾ��ʧ��" << endl;
    }
    return 0;
}