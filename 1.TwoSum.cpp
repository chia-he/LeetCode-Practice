/*
    1. Brute Force: 
        Using two layers of for loops, we can iterate over all the numbers in the given array.
        Check for equality with the target through pairwise summation.     
        Time: O(n^2), Space: O(1)
    2. Hash Table:
        Put all number into a hash map.
        Using a for loop to find complement of numbers whether in the hash map or not.
        Time: O(n), Space: O(n)
    3. Sorting:
        Sort the numbers in the given array.
        Verify equality with the target by employing pairwise summation with two pointers, one at the front and one at the back.
        Time: O(nlogn), Space: O(1)
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indies;
        for(int i=0; i<nums.size(); ++i) {
            indies[nums[i]] = i;  //{key: number value, value: index}
        }
        for(int i=0; i<nums.size(); ++i) {
            int complement = target - nums[i];
            if (indies.count(complement) && indies[complement]!=i){
                return {i, indies[complement]};
            }
        }
        return {};
    }
};
int main() {
    vector<int> nums = {11, 7, 2, 15};
    int target = 9;
    Solution solution;
    vector<int> result = solution.twoSum(nums, target);
    cout << "Output: " << result[0] << " " << result[1] << endl;
    return 0;
}

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
*/
/*
Constraints:
    1.  2 <= nums.length <= 10^4
    2.  -10^9 <= nums[i] <= 10^9
    3.  -10^9 <= target <= 10^9
    4.  Only one valid answer exists.
*/