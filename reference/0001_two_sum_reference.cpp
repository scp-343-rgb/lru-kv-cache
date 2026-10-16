// ============================================================
// 【参考答案 · 非本人产出】由 Codex 生成，仅作对照，不写进简历。
// 用法：自己先写 leetcode/0001_two_sum.cpp，卡壳 30 分钟后再看这份，
//       然后合上它默写一遍。看完请自己重写一份放回 leetcode/。
// ============================================================
// LeetCode 1. 两数之和 (Two Sum)
//
// 思路：一遍哈希表（边遍历边查、边存）
//   对每个 nums[i]，先看 target - nums[i] 是否已在表里：
//     在  -> 命中，返回 {表里的下标, i}
//     不在 -> 把 nums[i] -> i 存入表，继续
//   必须先查后存，否则 [3,3], target=6 会返回 {0,0}（同一个元素用两次）。
//
// 复杂度：时间 O(n)，空间 O(n)。
// 面试话术：暴力两重循环 O(n^2) -> 用哈希表把"找补数"从 O(n) 降到 O(1)。

#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(const std::vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;  // value -> index
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            auto it = seen.find(target - nums[i]);
            if (it != seen.end()) {
                return {it->second, i};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};

namespace {

void checkCase(const std::vector<int>& nums, int target, int want_a, int want_b,
               const std::string& name) {
    Solution sol;
    std::vector<int> got = sol.twoSum(nums, target);
    assert(got.size() == 2);

    // 顺序无关（题目允许任意顺序），并且两个下标不能相同
    bool ok = (got[0] != got[1]) &&
              ((got[0] == want_a && got[1] == want_b) ||
               (got[0] == want_b && got[1] == want_a));
    assert(ok);

    // 顺手验证答案确实成立
    assert(nums[got[0]] + nums[got[1]] == target);

    std::cout << "[PASS] " << name << " -> [" << got[0] << ", " << got[1] << "]\n";
}

}  // namespace

int main() {
    checkCase({2, 7, 11, 15}, 9, 0, 1, "示例 1");
    checkCase({3, 2, 4}, 6, 1, 2, "示例 2：补数在后");
    checkCase({3, 3}, 6, 0, 1, "示例 3：重复值必须用两个不同元素");
    checkCase({-3, 4, 3, 90}, 0, 0, 2, "负数 + 补数为 0");

    std::cout << "全部用例通过\n";
    return 0;
}
