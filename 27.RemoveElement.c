/*
    Time Complexity: O(n), Space Complexity: O(1)
*/
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val) {
    int index = 0;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] != val) {
            nums[index++] = nums[i];
        }
    }
    return index;
}
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int main(void) {
    int nums[] = {4, 5}; // Input array
    int val = 5; // Value to remove
    int expectedNums[] = {4}; // The expected val_countwer with correct length.
                                // It is sorted with no values equaling val.
    size_t size_nums = sizeof(nums)/sizeof(*nums);
    int k = removeElement(nums, size_nums, val); // Calls your implementation

    assert(k == sizeof(expectedNums)/sizeof(*expectedNums));
    
    qsort(nums, k, sizeof(*nums), compare); // Sort the first k elements of nums
    
    for (int i = 0; i < k; i++) {
        assert(nums[i] == expectedNums[i]);
    }
}

/*
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
    1. Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
    2. Return k.

*/
/*
Constraints:
    1.  0 <= nums.length <= 100
    2.  0 <= nums[i] <= 50
    3.  0 <= val <= 100
*/