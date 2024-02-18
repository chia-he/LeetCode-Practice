#include <iostream>
#include <vector>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        
        std::unordered_map<int, int> numMap;
        int n = static_cast<int>(nums.size());

        // Build a hash table
        for (int i = 0; i < n; i++) {
            numMap[nums[i]] = i;
        }
        // Find the complement
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            // Check complement in map and it's not itself
            if (numMap.count(complement) && numMap[complement] != i){
                return {i, numMap[complement]};
            }
        }

        return {}; // No solution found
    }
};

int main() {
    std::vector<int> nums = {11, 7, 2, 15};
    int target = 9;
    Solution solution;
    std::vector<int> result = solution.twoSum(nums, target);
    std::cout << "Output: " << result[0] << " " << result[1] << std::endl;
    return 0;
}