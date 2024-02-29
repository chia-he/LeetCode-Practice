/*
    Time: O(n), Space: O(1)
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            int n = digits.size();
            for (int i = n - 1; i >= 0; --i) {
                if (digits[i] != 9) {
                    ++digits[i];
                    return digits;
                }
                digits[i] = 0;
            }
            digits.insert(digits.begin(), 1);
            return digits;
        }
};
int main() {
    vector<int> digits = {9, 9, 9, 9};
    vector<int> k = Solution().plusOne(digits);

    for (auto i : k) {
        cout << i << " ";
    }
    return 0;
};

/*
You are given a large integer represented as an integer array digits, where each
digits[i] is the ith digit of the integer. The digits are ordered from most
significant to least significant in left-to-right order. The large integer does
not contain any leading 0's. Increment the large integer by one and return the
resulting array of digits.
*/
/*
Constraints:
    1.  1 <= digits.length <= 100
    2.  0 <= digits[i] <= 9
    3.  digits does not contain any leading 0's.
*/