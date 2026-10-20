#include <iostream>
#include <vector>
using namespace std;
int maxArea(vector<int>& height)
{
    size_t len = height.size();
    if (len < 2) return 0;
    size_t right = len - 1, left = 0;
    int max_ = 0;
    while (left < right) {
        int temp;
        if (height[left] >= height[right]) {
            temp = (right - left) * height[right];
            right--;
        }
        else {
            temp = (right - left) * height[left];
            left++;
        }
        if (temp > max_) max_ = temp;
    }
    return max_;
}
int main()
{
    vector<int>nums1 = { 1,8,6,2,5,4,8,3,7 };
    cout << maxArea(nums1) << endl;
    vector<int>nums2 = { 1,1 };
    cout << maxArea(nums2) << endl;
    return 0;
}