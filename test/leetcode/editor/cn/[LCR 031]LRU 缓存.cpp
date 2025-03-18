//
// 运用所掌握的数据结构，设计和实现一个 LRU (Least Recently Used，最近最少使用) 缓存机制 。 
// 
//
// 实现 LRUCache 类： 
//
// 
// LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存 
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。 
// void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上
//限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。 
// 
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
// 
//
// 进阶：是否可以在 O(1) 时间复杂度内完成这两种操作？ 
//
// 
//
// 
// 注意：本题与主站 146 题相同：https://leetcode-cn.com/problems/lru-cache/ 
//
// Related Topics 设计 哈希表 链表 双向链表 👍 110 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class LRUCache {
public:

    const static int maxn = 10010;

    struct node {
        int key, val;
        node *next, *prev;

        node() {
            key = 0;
            val = 0;
            prev = nullptr;
            next = nullptr;
        }

        node(int _key, int _val) {
            key = _key;
            val = _val;
            next = nullptr;
            prev = nullptr;
        }
    };

    int index = -1;
    node *_hash[maxn];
    int max_length, cur_length = 0;
    node *head, *tail;

    LRUCache(int capacity) {
        max_length = capacity;
        for (int i = 0; i < maxn; i += 1) _hash[i] = nullptr;
        head = new node();
        tail = new node();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (_hash[key] == nullptr) return -1;
        node *cur = _hash[key];
        change_to_head(cur);
        return cur->val;
    }

    void put(int key, int value) {
        if (_hash[key] != nullptr) {
            _hash[key]->val = value;
            change_to_head(_hash[key]);
            return;
        }
        if (cur_length < max_length) {
            cur_length += 1;
        } else {
            //删除最后一个节点
            node *t = tail->prev;
            _hash[t->key] = nullptr;
            t->prev->next = t->next;
            t->next->prev = t->prev;
            delete t;
        }
        node *tmp = new node(key, value);
        tmp->next = head->next;
        head->next->prev = tmp;
        tmp->prev = head;
        head->next = tmp;
        _hash[key] = tmp;
    }

    void change_to_head(node *cur) {
        node *p = cur->prev;
        node *n = cur->next;
        //将cur抽出
        p->next = n;
        n->prev = p;
        //将cur接到头结点下
        n = head->next;
        n->prev = cur;
        cur->next = n;
        cur->prev = head;
        head->next = cur;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)
