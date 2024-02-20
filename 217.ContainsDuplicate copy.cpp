/*
    1. Brute Force
    Time Complexity: O(n^2), Space Complexity: O(1)
    2. Sorting
    Time Complexity: O(nlogn), Space Complexity: O(1)
    3. Hash Table
    Time Complexity: O(n), Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int n: nums){
            if(++mp[n] >= 2)
                return true;
        }
        return false;
    }
};
int main(void){
    vector<int> nums{1,1};
    int ans = Solution().containsDuplicate(nums);
    cout << ans << endl;
    return 0;
};
/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/
/*
Constraints:
    1.  1 <= nums.length <= 10^5
    2.  -10^9 <= nums[i] <= 10^9
*/