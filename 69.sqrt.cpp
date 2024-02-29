/*
    Binary Search.
    Tips. s+(e-s)/2 to avoid overflow.
    Tips. divide instead of multiply to avoid overflow.
    Time: O(nlogn), Space: O(1)
*/
#include <iostream>
using namespace std;

class Solution {
    public:
        int mySqrt(int x) {
            if (x == 0 || x == 1) return x;
            int left = 1;
            int right = x;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (mid > x / mid)
                    right = mid - 1;
                else if (mid < x / mid)
                    left = mid + 1;
                else
                    return mid;
            }
            return right;
        }
};
int main() {
    int ans = Solution().mySqrt(8192);
    cout << ans << " ";
    return 0;
}

/*
Given a non-negative integer x, return the square root of x rounded down to the
nearest integer. The returned integer should be non-negative as well. You must
not use any built-in exponent function or operator.
- For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
*/
/*
Constraints:
    1.  0 <= x <= 2^31 - 1
*/