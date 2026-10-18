#include <iostream>
using namespace std;
void moveZeros(int nums[], int len)
{
    int right = 0;
    for (int left = 0;left < len;left++) {
        if (nums[left] != 0) {
            nums[right] = nums[left];
            right++;
        }
    }
    for (;right < len;right++) {
        nums[right] = 0;
    }
}
int main()
{
    int nums1[5] = { 0,1,0,3,12 };
    moveZeros(nums1, sizeof(nums1) / sizeof(nums1[0]));
    for (int i = 0;i < 5;i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;
    int nums2[1] = { 0 };
    moveZeros(nums2, sizeof(nums2) / sizeof(nums2[0]));
    cout << nums2[0] << endl;
    int nums3[4] = { 1,0,0,2 };
    moveZeros(nums3, sizeof(nums3) / sizeof(nums3[0]));
    for (int i = 0;i < 4;i++) {
        cout << nums3[i] << " ";
    }
    cout << endl;
    int nums4[3] = { 1,2,3 };
    moveZeros(nums4, sizeof(nums4) / sizeof(nums4[0]));
    for (int i = 0;i < 3;i++) {
        cout << nums4[i] << " ";
    }
    cout << endl;
    return 0;
}