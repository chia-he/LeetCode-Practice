/*
    1. Brute Force
        There are a total of n^2 such substrings (excluding the trivial solution where a character itself is a palindrome). Since verifying each substring takes O(n) time, the run time complexity is O(n^3). 
        Time Complexity: O(n^3), Space Complexity: O(1) 
    2. Expand Around Center
        Time Complexity: O(n^2), Space Complexity: O(1)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void substr(char* s, char* new_s, int start, int len) {
    strncpy(new_s, s + start, len);
    new_s[len] = '\0';
}
int isPalindrome(char* s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}
char* longestPalindrome_ExpandAroundCenter(char* s) {
    int len = strlen(s);
    if (len <= 1) return s;

    int max_len = 1;
    char* max_str = (char*)malloc(sizeof(char) * 2);
    max_str[0] = s[0];
    max_str[1] = '\0';

    return max_str;
}
char* longestPalindrome_BruteForce(char* s) {
    int len = strlen(s);
    if (len <= 1) return s;

    int max_len = 1;
    char* max_str = (char*)malloc(sizeof(char) * 2);
    max_str[0] = s[0];
    max_str[1] = '\0';

    for (int i = 0; i < len - 1; i++) {
        for (int j = max_len; j < len; j++) {
            if (j - i + 1 <= max_len) continue;
            if (isPalindrome(s, i, j)) {
                max_len = j - i + 1;
                max_str = (char*)realloc(max_str, sizeof(char) * (max_len + 1));
                substr(s, max_str, i, max_len);
            }
        }
    }
    return max_str;
}

int main() {
    char s[] = "dd";
    char* ans = longestPalindrome_ExpandAroundCenter(s);
    printf("%s\n", ans);
    free(ans);
}

/*
Given a string s, return the longest palindromic substring in s.
*/
/*
Constraints:
    1. 1 <= s.length <= 1000
    2. s consist of only digits and English letters.
*/