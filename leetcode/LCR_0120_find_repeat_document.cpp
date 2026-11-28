#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

int findRepeatDocument(vector<int>& documents)
{
    unordered_map<int, int>map;
    for (size_t i = 0;i < documents.size();i++) {
        auto it = map.find(documents[i]);
        if (it != map.end()) return it->first;
        map.try_emplace(documents[i], i);
    }
    return 0;
}

int findRepeatDocument(vector<int>& documents)
{
    for (size_t i = 0;i < documents.size();) {
        size_t temp = documents[i];
        if (temp == i)i++;
        else if (temp == documents[temp])return temp;
        else swap(documents[temp], documents[i]);
    }
    return 0;
}