#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/* 
LRU缓存机制： Least Recently Used，缓存大小超过容量大小时，将最近最少使用的数据淘汰
解决思路：哈希表+双向列表；哈希表为普通的哈希影射，存储key和value；双向列表按顺序存储键值对，头部键值最近使用，尾部最久未使用
参考：https://leetcode-cn.com/problems/lru-cache/solution/lruhuan-cun-ji-zhi-by-leetcode-solution/
 */

struct DListNode {
    int key;
    int val;
    DListNode *pre;
    DListNode *next;
    DListNode(): key(0), val(0), pre(nullptr), next(nullptr) {}
    DListNode(int k, int v): key(k), val(v), pre(nullptr), next(nullptr) {} 
  };

class LRUCache {
private:
  std::unordered_map<int, DListNode*> cache;  // 哈希表+双向列表 缓存map
  DListNode *head, *tail;
  int size;
  int capacity;
public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    head = new DListNode();
    tail = new DListNode();
    head->next = tail;
    tail->pre = head;
  }
  
  int get(int key) {
    if (!cache.count(key)) return -1; // key不存在
    // key存在，先通过哈希表定位，再将key所在的结点移到双向列表头部
    DListNode *node = cache[key];
    MoveToHead(node);
    return node->val;
  }
  
  void put(int key, int value) {
    if (!cache.count(key)) {
      // key 不存在，创建node以及新的map键值对，并将node移到双向列表头部
      DListNode *node = new DListNode(key, value); 
      cache[key] = node;
      AddToHead(node);
      ++size;
      if (size > capacity) {
        // 超过缓存容量，需要删除双向列表的尾部结点
        DListNode *remove_node = RemoveTailNode();
        cache.erase(remove_node->key);
        delete remove_node;   // 防止内存泄露
        --size;
      }
    } else {
      // 如果key存在，先通过哈希表定位，然后修改val值，并将node移到双向列表头部
      DListNode *node = cache[key];
      node->val = value;
      MoveToHead(node);
    }
  }
private:
  void RemoveNode(DListNode *node) {  // node->pre node node->next
    node->pre->next = node->next;
    node->next->pre = node->pre;
  }
  void MoveToHead(DListNode *node) {
    RemoveNode(node);
    AddToHead(node);
  }
  void AddToHead(DListNode *node) { // head node head->next  相当于将node插入head和head->next之间
    node->pre = head;
    node->next = head->next;
    head->next->pre = node;
    head->next = node;
  }
  DListNode* RemoveTailNode() {
    DListNode *tail_node = tail->pre;
    RemoveNode(tail_node);
    return tail_node;
  }
};


int main(int args, char **argv) {
  std::cout << "hello lch" << std::endl;
  std::shared_ptr<LRUCache> lru_cache = std::make_shared<LRUCache>(2);
  lru_cache->put(1, 1); // 缓存是 {1=1}
  lru_cache->put(2, 2); // 缓存是 {1=1, 2=2}
  std::cout << lru_cache->get(1) << std::endl;    // 返回 1
  lru_cache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
  std::cout << lru_cache->get(2) << std::endl;    // 返回 -1 (未找到)
  lru_cache->put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
  std::cout << lru_cache->get(1) << std::endl;    // 返回 -1 (未找到)
  std::cout << lru_cache->get(3) << std::endl;    // 返回 3
  std::cout << lru_cache->get(4) << std::endl;    // 返回 4

  std::cout << "end lch" << std::endl;
  return 0;
}
