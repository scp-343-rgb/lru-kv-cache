#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "list.h"
#include "lru_cache.h"
using namespace std;
int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "参数数量错误" << endl;
        return 1;
    }
    try {
        int capacity = stoi(argv[1]);
        LRUCache cache(capacity);
        string line;
        while (getline(cin, line)) {
            string cmd, tokens, key, value;
            int cnt = 0;
            istringstream iss(line);
            while (iss >> tokens) {
                if (cnt == 0) cmd = tokens;
                else if (cnt == 1) key = tokens;
                else if (cnt == 2) value = tokens;
                cnt++;
            }
            if (cmd == "put" && cnt == 3) {
                cache.put(key, value);
                cout << "OK" << endl;
            }
            else if (cmd == "get" && cnt == 2) {
                if (cache.get(key, value)) {
                    cout << "value=" << value << endl;
                }
                else {
                    cout << "NOT_FOUND" << endl;
                }
            }
            else if (cmd == "exit" && cnt == 1) {
                return 0;
            }
            else if (cnt == 0) {

            }
            else {
                cout << "ERR invalid command" << endl;
            }
        }
    }
    catch (const exception& e) {
        cerr << "无效参数: " << e.what() << endl;
        return 1;
    }
    return 0;
}
