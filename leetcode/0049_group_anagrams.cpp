#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> m;
    for (const string& s : strs) {
        string key = s;      // 空1：怎么把 "eat" 变成 "aet"
        sort(key.begin(), key.end());
        m[key].push_back(s);  // 空2：用哪个变量当 key；空3：放进去的是什么
    }
    vector<vector<string>> res;
    for (auto&p: m) res.push_back(p.second);  // 空4：怎么遍历 map，怎么取出那一桶
    return res;
}
int main()
{
    string str[3] = { "tea", "ate", "bat" };
    sort(str, str+3);
    for (int i = 0;i < 3;i++) {
        cout << str[i] << " ";
    }
    cout << endl;
    return 0;
}