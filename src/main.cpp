#include <iostream>
#include <string>
#include <sstream>
#include "list.h"
using namespace std;
int main() {
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
            cout << "PUT " << key << "=" << value << endl;
        }
        else if (cmd == "get" && cnt == 2) {
            cout << "GET " << key << endl;
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
    return 0;
}
