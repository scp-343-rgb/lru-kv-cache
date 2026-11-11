#include <mutex>
#include <string>
#include "thread_safe.h"

void ThreadSafeLRUCache::put(const std::string& key, const std::string& value)
{
    std::lock_guard<std::mutex>lock(mtx);
    cache.put(key, value);
}

bool ThreadSafeLRUCache::get(const std::string& key, std::string& value)
{
    std::lock_guard<std::mutex>lock(mtx);
    return cache.get(key, value);
}

bool ThreadSafeLRUCache::dumpFile(const std::string& path) const
{
    std::lock_guard<std::mutex>lock(mtx);
    return cache.dumpFile(path);
}

bool ThreadSafeLRUCache::loadFile(const std::string& path)
{
    std::lock_guard<std::mutex>lock(mtx);
    return cache.loadFile(path);
}