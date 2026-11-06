#include <unordered_map>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int, int>seen;
    vector<int>temp;
    for (size_t i = 0;i < nums.size();i++) {
        int need = target - nums[i];
        auto it = seen.find(need);
        if (it != seen.end()) {
            temp.push_back(i);
            temp.push_back(it->second);
            break;
        }
        else seen.emplace(nums[i], i);
    }
    return temp;
}