#pragma once
#include <unordered_map>
#include <string>
#include "list.h"
class LRUCache {
    int capacity_;
    List list_;
    std::unordered_map<std::string, Node*>index_;
public:
    explicit LRUCache(int c) :capacity_(c) {

    }
    bool get(const std::string& key, std::string& value);
    void put(const std::string& key, const std::string& value);
};