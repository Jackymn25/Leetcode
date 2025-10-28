#include <vector>
#include <unordered_map>
#include <iostream>
// //1. 两数之和  111
// 已解答
// 简单
// 相关标签
// premium lock icon
// 相关企业
// 提示
// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
//
// 你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。
//
// 你可以按任意顺序返回答案。
//
//
//
// 示例 1：
//
// 输入：nums = [2,7,11,15], target = 9
// 输出：[0,1]
// 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
// 示例 2：
//
// 输入：nums = [3,2,4], target = 6
// 输出：[1,2]
// 示例 3：
//
// 输入：nums = [3,3], target = 6
// 输出：[0,1]
//
//
// 提示：
//
// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// 只会存在一个有效答案
//
//
// 进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> index;

        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];
            if (index.count(need)) {
                return { index[need], i };
            }
            index[nums[i]] = i;
        }
        return {};
    }
};
//test case
int main() {
    Solution sol;

    // 测试用例 1
    {
        std::vector<int> nums = {2, 7, 11, 15};
        int target = 9;
        auto ans = sol.twoSum(nums, target);
        std::cout << "Test1: ";
        if (!ans.empty()) {
            std::cout << ans[0] << " " << ans[1] << "\n";
        } else {
            std::cout << "No solution\n";
        }
    }

    // 测试用例 2
    {
        std::vector<int> nums = {3, 2, 4};
        int target = 6;
        auto ans = sol.twoSum(nums, target);
        std::cout << "Test2: ";
        if (!ans.empty()) {
            std::cout << ans[0] << " " << ans[1] << "\n";
        } else {
            std::cout << "No solution\n";
        }
    }

    // 测试用例 3
    {
        std::vector<int> nums = {3, 3};
        int target = 6;
        auto ans = sol.twoSum(nums, target);
        std::cout << "Test3: ";
        if (!ans.empty()) {
            std::cout << ans[0] << " " << ans[1] << "\n";
        } else {
            std::cout << "No solution\n";
        }
    }

    return 0;
}

// Test1: 0 1
// Test2: 1 2
// Test3: 0 1
