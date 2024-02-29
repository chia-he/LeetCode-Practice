/*
    1. Brute Force:
        Time Complexity: O(n^2), Space Complexity: O(1)
    2. Two Pointers (Greedy):
        Time Complexity: O(n), Space Complexity: O(1)
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int maxArea(int* height, int heightSize) {
    int maxArea = 0;
    int left = 0;
    int right = heightSize - 1;
    while (left < right) {
        int h = MIN(height[left], height[right]);
        int w = right - left;
        maxArea = MAX(maxArea, h * w);
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return maxArea;
}
int maxArea_brute(int* height, int heightSize) {
    int max_area = 0;
    for (int i = 0; i < heightSize; i++) {
        for (int j = i + 1; j < heightSize; j++) {
            int w = j - i;
            int h = MIN(height[i], height[j]);
            int area = w * h;
            if (area > max_area) {
                max_area = area;
            }
        }
    }
    return max_area;
}

int main(void) {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int heightSize = sizeof(height) / sizeof(height[0]);
    printf("%d\n", maxArea(height, heightSize));
}

/*
You are given an integer array height of length n. There are n vertical lines
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the
container contains the most water. Return the maximum amount of water a
container can store. Notice that you may not slant the container.
*/
/*
Constraints:
    1. n == height.length
    2. 2 <= n <= 10^5
    3. 0 <= height[i] <= 10^4
*/