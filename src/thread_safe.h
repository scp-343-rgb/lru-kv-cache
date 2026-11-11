#pragma once
#include <mutex>
#include <string>
#include "lru_cache.h"

class ThreadSafeLRUCache
{
    LRUCache cache;
    mutable std::mutex mtx;
public:
    explicit ThreadSafeLRUCache(int c) :cache(c) {

    }
    bool get(const std::string& key, std::string& value);
    void put(const std::string& key, const std::string& value);
    bool dumpFile(const std::string& path) const;
    bool loadFile(const std::string& path);
};
