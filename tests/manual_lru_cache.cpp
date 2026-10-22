#include "lru_cache.h"
#include <iostream>
#include <string>
using namespace std;
int main() {
    string value = "0";
    LRUCache cache(2);
    cache.put("a", "1");
    cache.put("b", "3");
    cache.put("a", "2");
    cout << cache.get("a", value) << "value=" << value << endl;
    cout << cache.get("b", value) << endl;
    //cout << cache.get("c", value) << endl;
    return 0;
}