#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (size_t i = 0;i < nums.size();i++) {
        size_t left = i + 1, right = nums.size() - 1;
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        while (left < right) {
            if (nums[left] + nums[right] > -nums[i]) right--;
            else if (nums[left] + nums[right] < -nums[i]) left++;
            else {
                res.push_back({ nums[i],nums[left],nums[right] });
                left++;
                right--;
                while (left < right && nums[left - 1] == nums[left]) left++;
                while (left < right && nums[right + 1] == nums[right]) right--;
            }
        }
    }
    return res;
}
int main()
{
    vector<int> nums1 = { 0, 0, 0 };
    vector<vector<int>>nums1_ = threeSum(nums1);
    cout << "[";
    for (size_t i = 0;i < nums1_.size();i++) {
        cout << "[";
        for (size_t j = 0;j < nums1_[i].size();j++) {
            cout << nums1_[i][j] << ",";
        }
        cout << "]";
    }
    cout << "]" << endl;
    return 0;
}