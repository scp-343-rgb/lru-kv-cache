#pragma once
#include<string>
class Node {
    std::string key_;
    std::string value_;
    Node* prev_;
    Node* next_;
    friend class List;
public:
    Node(const std::string& k, const std::string& v, Node* p = nullptr, Node* n = nullptr) :
        key_(k), value_(v), prev_(p), next_(n) {

    }
    const std::string& key()const {
        return key_;
    }
    const std::string& value()const {
        return value_;
    }
    Node* next()const {
        return next_;
    }
    void setvalue(const std::string& value) {
        this->value_ = value;
    }
};
class List {
    Node* head;
    Node* tail;
    int size_;
public:
    List() :head(new Node("", "")), tail(new Node("", "")), size_(0) {
        head->next_ = tail;
        tail->prev_ = head;
    }
    ~List() {
        Node* p = head->next_;
        while (p != tail) {
            Node* r = p->next_;
            delete p;
            p = r;
        }
        delete head;
        delete tail;
    }
    int size()const {
        return size_;
    }
    bool empty() const {
        return head->next_ == tail;
    }
    Node* front() const {
        return head->next_;
    }
    Node* back() const {
        return tail->prev_;
    }
    Node* end()const {
        return tail;
    }
    void addToHead(Node* node);
    void removeNode(Node* node);
    void moveToHead(Node* node);
};
