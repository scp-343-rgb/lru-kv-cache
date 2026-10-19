#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    sort(nums.begin(), nums.end());
    int max_ = 1, cnt = 1;
    for (size_t i = 1;i < nums.size();i++) {
        if (nums[i] - nums[i - 1] == 1) cnt++;
        else if (nums[i] - nums[i - 1] == 0) {}
        else cnt = 1;
        if (cnt > max_) max_ = cnt;
    }
    return max_;
}
int main()
{
    vector<int> nums1 = { 100,4,200,1,3,2 };
    cout << longestConsecutive(nums1) << endl;
    vector<int>nums2 = { 0,3,7,2,5,8,4,6,0,1 };
    cout << longestConsecutive(nums2) << endl;
    vector<int>nums3 = { 1,0,1,2 };
    cout << longestConsecutive(nums3) << endl;
    vector<int>nums4 = { 1 };
    cout << longestConsecutive(nums4) << endl;
    return 0;
}