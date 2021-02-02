#include <bits/stdc++.h>
using namespace std;

/**
* LRU 
* 最近最少使用，O(1) 的时间复杂度，可以使用一个双向链表和哈希表来实现
* 1. put
*       新增节点，将节点保存到链表的头节点，如果增加之后的容量大于最大容量，那么删除末尾节点
* 2. get
*       获取节点内容，并且把节点放到链表头部
* 
*/

class LRUCache {
private:
    // 用于保存双向链表的节点结构
    struct DlinkedNode{
        int key, val;
        DlinkedNode* pre;
        DlinkedNode* next;
        DlinkedNode() : key(0), val(0), pre(nullptr), next(nullptr) {};
        DlinkedNode(int t_key, int t_val):key(t_key), val(t_val), pre(nullptr), next(nullptr) {}; 
    };
private:
    int m_capatity;
    int size;
    unordered_map<int, DlinkedNode*> cache;
    DlinkedNode* dumpHead;
    DlinkedNode* dumpTail;
public:
    LRUCache(int capacity): m_capatity(capacity), size(0) {
        dumpHead = new DlinkedNode();
        dumpTail = new DlinkedNode();
        dumpHead->next = dumpTail;
        dumpTail->pre = dumpHead;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;
        auto node = cache[key];
        move_front(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (cache.find(key) == cache.end()) {
            DlinkedNode* newNode = new DlinkedNode(key, value);
            cache.insert({ key, newNode });
            add_to_head(newNode);
            ++size;
            if (size > m_capatity) {
                DlinkedNode* deleteNode = remove_last();
                cache.erase(deleteNode->key);
                delete deleteNode;
                --size;
            }
        }else {
            DlinkedNode* node = cache[key];
            node->val = value;
            move_front(node);
        }
    }
private:
    void add_to_head(DlinkedNode* node) {
        node->pre = dumpHead;
        node->next = dumpHead->next;
        dumpHead->next->pre = node;
        dumpHead->next = node;
    }
    
    DlinkedNode* remove_last() {
        DlinkedNode* node = dumpTail->pre;
        remove_node(node);
        return node;
    }
    
    void remove_node(DlinkedNode* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    
    void move_front(DlinkedNode* node) {
        remove_node(node);
        add_to_head(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(int argc, char const *argv[])
{ 
    LRUCache lRUCache = LRUCache(2);
    lRUCache.put(1, 1); // 缓存是 {1=1}
    lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    lRUCache.get(1);    // 返回 1
    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    lRUCache.get(2);    // 返回 -1 (未找到)
    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    lRUCache.get(1);    // 返回 -1 (未找到)
    lRUCache.get(3);    // 返回 3
    lRUCache.get(4);    // 返回 4
        
    return 0;
}