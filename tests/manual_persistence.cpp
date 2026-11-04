#include "lru_cache.h"
#include <string>
#include <iostream>
using namespace std;
int main() {
    string value = "0";
    /*LRUCache cache(2);
    cache.put("a", "1");
    cache.put("b", "2");
    cache.get("a", value);
    cache.dumpFile("build/manual_persistence.txt");
    cache.put("c", "3");
    cache.dumpFile("build/manual_persistence.txt");
    LRUCache empty(1);
    cout << "build/empty_cache.txt : " << empty.dumpFile("build/empty_cache.txt") << endl;
    cout << "build/no_such_dir/cache.txt : " << cache.dumpFile("build/no_such_dir/cache.txt") << endl;
    LRUCache restored(2);
    cout << "build/manual_persistence.txt : " << restored.loadFile("build/manual_persistence.txt") << endl;
    bool oka = restored.get("a", value);
    cout << "a : " << oka << endl;
    cout << "a.value= " << value << endl;
    bool okc = restored.get("c", value);
    cout << "c : " << okc << endl;
    cout << "c.value= " << value << endl;
    restored.put("d", "4");
    LRUCache order(2);
    order.loadFile("build/manual_persistence.txt");
    order.put("d", "4");
    bool oka_1 = order.get("a", value);
    cout << "a : " << oka_1 << endl;
    cout << "a.value= " << value << endl;
    bool okc_1 = order.get("c", value);
    cout << "c : " << okc_1 << endl;
    cout << "c.value= " << value << endl;*/
    LRUCache test(2);
    bool t = test.loadFile("build/load_invalid.txt");
    cout << test.get("c", value) << " " << value << endl;
    cout << test.get("a", value) << " " << value << endl;
    cout << "load result: " << t << endl;
    return 0;
}