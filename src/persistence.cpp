#include "lru_cache.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
bool LRUCache::dumpFile(const std::string& path) const
{
    std::ofstream file;
    file.open(path);
    if (!file) return false;
    for (Node* i = list_.front();i != list_.end();i = i->next()) {
        file << i->key() << "\t" << i->value() << '\n';
    }
    file.close();
    if (file.fail()) {
        std::cerr << "文件可能未完全写入" << '\n';
        return false;
    }
    return true;
}
bool LRUCache::loadFile(const std::string& path)
{
    std::ifstream file;
    file.open(path);
    if (!file) return false;
    std::string line;
    std::size_t lineNo = 0;
    std::vector<std::pair<std::string, std::string>>v;
    while (std::getline(file, line)) {
        lineNo++;
        if(line.empty()) continue;
        std::size_t tab = line.find('\t');
        if (tab == std::string::npos) {
            std::cerr << "第" << lineNo << "行缺少制表符，已跳过" << std::endl;
            continue;
        }
        else if (tab == 0) {
            std::cerr << "第" << lineNo << "行key为空，已跳过" << std::endl;
            continue;
        }
        else if (tab == line.size() - 1) {
            std::cerr << "第" << lineNo << "行value为空，已跳过" << std::endl;
            continue;
        }
        std::size_t second = line.find('\t', tab + 1);
        if (second != std::string::npos) {
            std::cerr << "第" << lineNo << "行有多个制表符，已跳过" << std::endl;
            continue;
        }
        std::string key = line.substr(0, tab);
        std::string value = line.substr(tab + 1);
        v.emplace_back(key, value);
    }
    for (auto it = v.rbegin();it != v.rend();++it) {
        put(it->first, it->second);
    }
    return true;
}