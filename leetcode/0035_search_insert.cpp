#include <vector>
#include <algorithm>
using namespace std;
/*int searchInsert(vector<int>& nums, int target)
{
    auto it = find(nums.begin(), nums.end(), target);
    if (it != nums.end()) return it - nums.begin();
    else {
        nums.push_back(target);
        sort(nums.begin(), nums.end());
        auto index = find(nums.begin(), nums.end(), target);
        return index-nums.begin();
    }
}*/
int searchInsert(vector<int>& nums, int target)
{
    int left = -1, right = nums.size();
    while (left + 1 != right) {
        int mid = (left + right) / 2;
        if (nums[mid] > target) right = mid;
        else if (nums[mid] < target) left = mid;
        else return mid;
    }
    return right;
}