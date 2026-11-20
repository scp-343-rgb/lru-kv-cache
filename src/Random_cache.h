#pragma once
#include <string>
#include <vector>
#include <random>
#include <unordered_map>
#include <stdexcept>

class RandomCache {
    std::unordered_map<std::string, std::string>values;
    std::vector<std::string>keys;
    std::mt19937 rng;
    int capacity;
public:
    explicit RandomCache(int c) :rng(20261116),capacity(c){
        if (capacity <= 0) throw std::invalid_argument("容量必须大于零");
    }
    void put(const std::string& key, const std::string& value);
    bool get(const std::string& key, std::string& value);
};