#include "lru_cache.h"
bool LRUCache::get(const std::string& key, std::string& value)
{
    auto it = index_.find(key);
    if (it != index_.end()) {
        value = it->second->value();
        list_.moveToHead(it->second);
        return true;
    }
    return false;
}
void LRUCache::put(const std::string& key, const std::string& value)
{
    auto it = index_.find(key);
    if (it != index_.end()) {
        it->second->setvalue(value);
        list_.moveToHead(it->second);
    }
    else {
        while (list_.size() >= capacity_)
        {
            Node* node = list_.back();
            index_.erase(node->key());
            list_.removeNode(node);
            delete node;
        }
        Node* node = new Node(key, value);
        list_.addToHead(node);
        index_.emplace(key, node);
    }
}