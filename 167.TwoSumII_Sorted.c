/*

*/

#include <stdio.h>
#include <stdlib.h>
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int left = 0;
    int right = numbersSize - 1;
    int sum;
    while (left < right) {
        sum = numbers[left] + numbers[right];
        if (sum == target) {
            int* result = (int*)malloc(sizeof(int) * 2);
            result[0] = left + 1;
            result[1] = right + 1;
            *returnSize = 2;
            return result;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return NULL;
}
int main(void) {
    int numbers[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int* ptr =
        twoSum(numbers, sizeof(numbers) / sizeof(int), target, &returnSize);
    for (int i = 0; i < 2; i++) {
        printf("%d ", *(ptr + i));
    }
    free(ptr);
}

/*
Given a 1-indexed array of integers numbers that is already sorted in
non-decreasing order, find two numbers such that they add up to a specific
target number. Let these two numbers be numbers[index1] and numbers[index2]
where 1 <= index1 < index2 <= numbers.length. Return the indices of the two
numbers, index1 and index2, added by one as an integer array [index1, index2] of
length 2. The tests are generated such that there is exactly one solution. You
may not use the same element twice. Your solution must use only constant extra
space.
*/
/*
Constraints:
    1. 2 <= numbers.length <= 3 * 10^4
    2. -1000 <= numbers[i] <= 1000
    3. numbers is sorted in non-decreasing order.
    4.-1000 <= target <= 1000
    5. The tests are generated such that there is exactly one solution.
*/