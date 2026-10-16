#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (size_t i = 0;i < nums.size();i++) {
            int complement = target - nums[i];
            for (size_t j = i + 1;j < nums.size();j++) {
                if (nums[j] == complement) {
                    return{ i,j };
                }
            }
        }
        return{};
    }
};
bool twoSum(int nums[], int len, int target, int* out_i, int* out_j)
{
    bool found = false;
    for (int i = 0;i < len;i++) {
        int complement = target - nums[i];
        for (int j = i + 1;j < len;j++) {
            if (nums[j] == complement) {
                *out_i = i;
                *out_j = j;
                found = true;
                break;
            }
        }
        if (found)break;
    }
    return found;
}
void runCase(int nums[], int len, int target, int exp_i, int exp_j, const string& name)
{
    vector<int> v;
    for (int k = 0; k < len; k++) v.push_back(nums[k]);
    vector<int> ans = Solution().twoSum(v, target);
    if (ans.size() == 0) {
        if (exp_i == -1) cout << name << " PASS " << endl;
        else cout << name << " FAIL got none expect[" << exp_i << "," << exp_j << "]" << endl;
    }
    else {
        if (ans[0] == exp_i && ans[1] == exp_j)cout << name << " PASS" << endl;
        else cout << name << " FAIL got " << ans[0] << "," << ans[1] <<
            " expect  [" << exp_i << "," << exp_j << "]" << endl;
    }
}
int main()
{
    int nums1[4] = { 2, 7, 11, 15 };
    runCase(nums1, sizeof(nums1) / sizeof(nums1[0]), 9, 0, 1, "case1 { 2, 7, 11, 15 }/9");
    int nums2[3] = { 3, 2, 4 };
    runCase(nums2, sizeof(nums2) / sizeof(nums2[0]), 6, 1, 2, "case2{ 3, 2, 4 }/6");
    int nums3[2] = { 3, 3 };
    runCase(nums3, sizeof(nums3) / sizeof(nums3[0]), 6, 0, 1, "case3{3,3}/6");
    int nums4[4] = { -3, 4, 3, 90 };
    runCase(nums4, sizeof(nums4) / sizeof(nums4[0]), 0, 0, 2, "case4{ -3, 4, 3, 90 }/0");
    int nums5[3] = { 1,2,3 };
    runCase(nums5, sizeof(nums5) / sizeof(nums5[0]), 100, -1, -1, "case5{1,2,3}/100");
    return 0;
}