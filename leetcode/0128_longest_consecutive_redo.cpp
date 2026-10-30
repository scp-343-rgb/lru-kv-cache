#include <algorithm>
#include <vector>
using namespace std;
int longestConsecutive(vector<int>& nums)
{
    if (nums.size() <= 1) return nums.size();
    sort(nums.begin(), nums.end());
    int max = 1, cnt = 1;
    for (size_t right = 1;right < nums.size();right++) {
        size_t left = right - 1;
        if (nums[left] == nums[right]) continue;
        else if (nums[left] + 1 == nums[right]) cnt++;
        else cnt = 1;
        if (cnt > max) max = cnt;
    }
    return max;
}