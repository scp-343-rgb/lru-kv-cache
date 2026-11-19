#pragma once
#include <string>
#include <queue>
#include <unordered_map>
#include <stdexcept>

class FIFOCache {
    std::queue <std::string> order;
    std::unordered_map<std::string, std::string> values;
    int capacity;
public:
    explicit FIFOCache(int c) :capacity(c) {
        if (capacity <= 0) throw std::invalid_argument("容量必须大于零");
    }
    void put(const std::string& key, const std::string& value);
    bool get(const std::string& key, std::string& value);
};