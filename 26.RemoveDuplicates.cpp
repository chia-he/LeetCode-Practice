/*
    Two Pointers, i and vacant, to iterate through the array.
    vacant is used to keep track where a unique element should be placed.
    Since the first element in the array is always unique, vacant starts at 1.
    Time Complexity: O(n)
    Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int vacant = 1;
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] != nums[i - 1]) {
                    nums[vacant] = nums[i];
                    ++vacant;
                }
            }
            return vacant;
        }
};
int main() {
    vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}; // Input array
    vector<int> expectedNums{0, 1, 2, 3,
                             4}; // The expected answer with correct length
    int k = Solution().removeDuplicates(nums); // Calls your implementation
    assert(k == expectedNums.size());
    for (int i = 0; i < k; i++) {
        assert(nums[i] == expectedNums[i]);
    }
    return 0;
};

/*
Given an integer array nums sorted in non-decreasing order, remove the
duplicates in-place such that each unique element appears only once. The
relative order of the elements should be kept the same. Then return the number
of unique elements in nums. Consider the number of unique elements of nums to be
k, to get accepted, you need to do the following things:
-   Change the array nums such that the first k elements of nums contain the
unique elements in the order they were present in nums initially. The remaining
elements of nums are not important as well as the size of nums.
-   Return k.
*/
/*
Constraints:
    1.  1 <= nums.length <= 3 * 10^4
    2.  -100 <= nums[i] <= 100
    3.  nums is sorted in non-decreasing order.
*/