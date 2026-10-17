#include <iostream>
#include <string>
using namespace std;
bool containsDuplicate(int nums[], int len, int& p, int& q)
{
    bool found = false;
    for (int i = 0;i < len;i++) {
        for (int j = i + 1;j < len;j++) {
            if (nums[i] == nums[j]) {
                found = true;
                p = i;
                q = j;
                break;
            }
        }
        if (found) break;
    }
    return found;
}
void runCase(int nums[], int len, int exp_i, int exp_j, const string& name)
{
    int p = -1, q = -1;
    if (containsDuplicate(nums, len, p, q)) {
        if (p == exp_i && q == exp_j) cout << name << " PASS" << endl;
        else cout << name << " FAIL got " << p << "," << q <<
            " expect  [" << exp_i << "," << exp_j << "]" << endl;
    }
    else {
        if (exp_i == -1)cout << name << " PASS" << endl;
        else cout << name << " FAIL got none expect[" << exp_i << "," << exp_j << "]" << endl;
    }
}
int main()
{
    int nums1[4] = { 1,2,3,1 };
    runCase(nums1, sizeof(nums1) / sizeof(nums1[0]), 0, 3, "case1 { 1,2,3,1 }");
    int nums2[4] = { 1,2,3,4 };
    runCase(nums2, sizeof(nums2) / sizeof(nums2[0]), -1, -1, "case2{ 1,2,3,4 }");
    int nums3[10] = { 1,1,1,3,3,4,3,2,4,2 };
    runCase(nums3, sizeof(nums3) / sizeof(nums3[0]), 0, 1, "case3{1,1,1,3,3,4,3,2,4,2 }");
    return 0;
}