#include <string>
using namespace std;

string pathEncryption(string path)
{
    size_t pos = 0;
    while ((pos = path.find('.',pos)) != string::npos) {
        path[pos] = ' ';
    }
    return path;
}