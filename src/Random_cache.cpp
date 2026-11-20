#include "Random_cache.h"

void RandomCache::put(const std::string& key, const std::string& value)
{
    auto it = values.find(key);
    if (it != values.end()) {
        values[key] = value;
    }
    else {
        if (static_cast<int>(keys.size()) >= capacity) {
            std::uniform_int_distribution<int> keydist(0, static_cast<int>(keys.size()) - 1);
            int randomIndex = keydist(rng);
            std::string temp = keys[randomIndex];
            values.erase(temp);
            keys[randomIndex] = keys.back();
            keys.pop_back();
        }
        values.emplace(key, value);
        keys.push_back(key);
    }
}

bool RandomCache::get(const std::string& key, std::string& value)
{
    auto it = values.find(key);
    if (it != values.end()) {
        value = it->second;
        return true;
    }
    return false;
}