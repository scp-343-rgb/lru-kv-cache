#pragma once
#include<string>
class Node {
    std::string key;
    std::string value;
    Node* prev;
    Node* next;
public:
    Node(const std::string& k, const std::string& v, Node* p = nullptr, Node* n = nullptr) :
        key(k), value(v), prev(p), next(n) {

    }
};
