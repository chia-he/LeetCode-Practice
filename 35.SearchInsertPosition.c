/*
 */

#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    // sorted array => binary search
    int left = 0;
    int right = numsSize;
    int mid;
    if (nums[left] > target)
        return left;
    else if (nums[right-1] < target)
        return right;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    // not found
    return left;
}
int main() {
    int nums[] = {1, 3};
    int target = 2;
    printf("%d\n", searchInsert(nums, sizeof(nums)/sizeof(int), target));
}
/*
Given a sorted array of distinct integers and a target value, return the index
if the target is found. If not, return the index where it would be if it were
inserted in order. You must write an algorithm with O(log n) runtime complexity.
*/
/*
Constraints:
    1. 1 <= nums.length <= 10^4
    2. -10^4 <= nums[i] <= 10^4
    3. nums contains distinct values sorted in ascending order.
    4. -10^4 <= target <= 10^4
*/