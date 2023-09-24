//
// 请你设计并实现一个满足 
// LRU (最近最少使用) 缓存 约束的数据结构。
// 
//
// 
// 实现 
// LRUCache 类：
// 
//
// 
// 
// 
// LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存 
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。 
// void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 
//key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。 
// 
// 
// 
//
// 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。 
//
// 
//
// 示例： 
//
// 
//输入
//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//输出
//[null, null, null, 1, null, -1, null, -1, 3, 4]
//
//解释
//LRUCache lRUCache = new LRUCache(2);
//lRUCache.put(1, 1); // 缓存是 {1=1}
//lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
//lRUCache.get(1);    // 返回 1
//lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
//lRUCache.get(2);    // 返回 -1 (未找到)
//lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
//lRUCache.get(1);    // 返回 -1 (未找到)
//lRUCache.get(3);    // 返回 3
//lRUCache.get(4);    // 返回 4
// 
//
// 
//
// 提示： 
//
// 
// 1 <= capacity <= 3000 
// 0 <= key <= 10000 
// 0 <= value <= 10⁵ 
// 最多调用 2 * 10⁵ 次 get 和 put 
// 
//
// Related Topics 设计 哈希表 链表 双向链表 👍 2918 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class LRUCache {
public:
    const static int N = 10010;

    struct List_node {
        int key, value;
        List_node *next, *prev;

        List_node() : key(0), value(0), next(nullptr), prev(nullptr) {}

        List_node(int key, int value) : key(key), value(value), next(nullptr), prev(nullptr) {}

        List_node(int value, List_node *next, List_node *prev) : value(value), next(next), prev(prev) {}
    } *head, *tail;

    List_node *hash[N];
    int capacity;
    int current_length = 0;

    LRUCache(int capacity) {
        head = new List_node();
        tail = new List_node();
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
        for (int i = 0; i < N; i++) {
            hash[i] = nullptr;
        }
    }

    int get(int key) {
        printf("get %d\n", key);
        if (hash[key] == nullptr) {
            return -1;
        } else {
            List_node *p = hash[key];
            p->prev->next = p->next;
            p->next->prev = p->prev;
            p->next = tail;
            p->prev = tail->prev;
            tail->prev->next = p;
            tail->prev = p;
            print_list();
            return p->value;
        }

    }

    void put(int key, int value) {
        printf("put %d %d\n", key, value);
        if (hash[key] == nullptr) {
            List_node *p = new List_node(key, value);
            p->next = tail;
            p->prev = tail->prev;
            tail->prev->next = p;
            tail->prev = p;
            hash[key] = p;
            this->current_length += 1;
        } else {
            List_node *p = hash[key];
            p->prev->next = p->next;
            p->next->prev = p->prev;
            p->next = tail;
            p->prev = tail->prev;
            tail->prev->next = p;
            tail->prev = p;
            p->key = key;
            p->value = value;
        }
        if (this->current_length > this->capacity) {
            List_node *p = head->next;
            head->next = p->next;
            p->next->prev = head;
            hash[p->key] = nullptr;
            delete p;
            this->current_length -= 1;
        }
        print_list();
    }

    void print_list() {
        return ;
        List_node *tmp = head;
        printf("当前链表开始 长度为%d：\n", this->current_length);
        while (tmp != tail) {
            tmp = tmp->next;
            printf("%d %d\n", tmp->key, tmp->value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)
