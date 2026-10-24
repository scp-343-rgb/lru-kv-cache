#include <iostream>
#include <unordered_map>
using namespace std;
struct Node {
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int k, int v, Node* n = nullptr, Node* p = nullptr) :
        key(k), value(v), next(n), prev(p) {

    }
};
struct List {
    Node* head;
    Node* tail;
    int size;
    List() :head(new Node(0, 0)), tail(new Node(0, 0)), size(0)
    {
        head->next = tail;
        tail->prev = head;
    }
    ~List() {
        Node* p = head->next;
        while (p != tail) {
            Node* r = p->next;
            delete p;
            p = r;
        }
        delete head;
        delete tail;
    }
    void addToHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
    }
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = nullptr;
        node->prev = nullptr;
        size--;
    }
    void moveToHead(Node* node) {
        removeNode(node);
        addToHead(node);
    }
};
class LRUCache {
public:
    int capacity_;
    List list;
    unordered_map<int, Node*>index_;
    LRUCache(int capacity) {
        capacity_ = capacity;
    }

    int get(int key) {
        auto it = index_.find(key);
        if (it != index_.end()) {
            list.moveToHead(it->second);
            return it->second->value;
        }
        return -1;
    }

    void put(int key, int value) {
        auto it = index_.find(key);
        if (it != index_.end()) {
            it->second->value = value;
            list.moveToHead(it->second);
        }
        else {
            while (capacity_ <= list.size) {
                Node* r = list.tail->prev;
                index_.erase(r->key);
                list.removeNode(r);
                delete r;
            }
            Node* node = new Node(key, value);
            list.addToHead(node);
            index_.emplace(key, node);
        }
    }
};