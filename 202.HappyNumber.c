/*
    1. Brute Force
        Time Complexity: O(n), Space Complexity: O(n)
    2. Two Pointer (slow fast)
        Time Complexity: O(n), Space Complexity: O(1)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int squareSum(int n) {
    int num = n;
    int ans = 0;
    // split the digit and sum of their square
    while (num > 0) {
        int remainder = num % 10;
        ans += remainder * remainder;
        num /= 10;
    }

    return ans;
}
bool isHappy(int n) {
    int slow = n;
    int fast = n;
    // Floyd's tortoise and hare.
    do {
        slow = squareSum(slow);
        fast = squareSum(squareSum(fast));
    } while ((slow != fast) && (fast != 1));
    // cycle not exists.
    return fast == 1;
}
bool isHappy_bruteforce(int n) {
    int ans = 0;
    int number = n;
    int counter = 0;
    int *set = (int *)malloc(0);
    while (1) {
        // split digits and sum the square of digits
        while (number > 0) {
            int remainder = number % 10;
            ans += remainder * remainder;
            number /= 10;
        }
        // check if it is equal to 1, or in a cycle
        if (ans == 1) {
            return true;
        } else {
            // in a cycle
            for (int i = 0; i < counter; i++) {
                if (set[i] == ans) return false;
            }
            set = (int *)realloc(set, sizeof(int) * (counter + 1));
            set[counter++] = ans;
            // continue
            number = ans;
            ans = 0;
        }
    }
}

int main(void) {
    int n = 18;
    printf("%d\n", isHappy(n));
}