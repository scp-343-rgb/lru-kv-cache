#include <vector>
using namespace std;
void moveZeroes(vector<int>& nums)
{
    size_t left = 0, right = 0;
    while (right < nums.size()) {
        if (nums[right] != 0) {
            nums[left] = nums[right];
            left++;
        }
        right++;
    }
    for (size_t k = left;k < nums.size();k++) {
        nums[k] = 0;
    }
}