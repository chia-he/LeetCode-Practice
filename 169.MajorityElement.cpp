/*
    1. Sorting
        Time Complexity: O(nlogn), Space Complexity: O(1)
    2. Hash Table
        Time Complexity: O(n), Space Complexity: O(n)
    3. Moore's Voting Algorithm
        Time Complexity: O(n), Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        // Voting
        for(int n: nums){
            if(count == 0) 
                candidate = n;
            count += (n == candidate)? 1 : -1;
        }
        // // Verification
        // count = 0;
        // for(int n: nums){
        //     if(n == candidate)
        //         ++count;
        // }
        // if (count > nums.size() / 2){
        //     return candidate;
        // }
        return candidate;
    }
};
int main(void){
    vector<int> nums{1,1,2,2,1,2,3,1};
    int ans = Solution().majorityElement(nums);
    cout << ans << endl;
    return 0;
};
/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/
/*
Constraints:
    1.  n == nums.length
    2.  1 <= n <= 5 * 10^4
    3.  -10^9 <= nums[i] <= 10^9
*/