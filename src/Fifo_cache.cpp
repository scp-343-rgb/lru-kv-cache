#include "Fifo_cache.h"

void FIFOCache::put(const std::string& key, const std::string& value)
{
    auto it = values.find(key);
    if (it != values.end()) {
        values[key] = value;
    }
    else {
        while (static_cast<int>(order.size()) >= capacity) {
            std::string temp = order.front();
            values.erase(temp);
            order.pop();
        }
        order.push(key);
        values.emplace(key, value);
    }
}

bool FIFOCache::get(const std::string& key, std::string& value)
{
    auto it = values.find(key);
    if (it != values.end()) {
        value = it->second;
        return true;
    }
    else return false;
}