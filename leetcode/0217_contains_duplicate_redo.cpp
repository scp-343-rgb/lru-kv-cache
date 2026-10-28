#include <algorithm>
#include <vector>
using namespace std;
bool containsDuplicate(vector<int>& nums)
{
    if (nums.size() == 1) return false;
    sort(nums.begin(),nums.end());
    size_t left = 0;
    size_t right = 1;
    while (right < nums.size()) {
        if (nums[left] == nums[right]) return true;
        left++;
        right++;
    }
    return false;
}