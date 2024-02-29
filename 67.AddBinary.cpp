/*
    Time: O(m+n), Space: O(m+n)
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        string addBinary(string a, string b) {
            int i = a.size() - 1;
            int j = b.size() - 1;
            int carry = 0;
            string ans = "";
            while (i >= 0 || j >= 0 || carry) {
                if (i >= 0) carry += a[i--] - '0';
                if (j >= 0) carry += b[j--] - '0';
                ans = to_string(carry % 2) + ans;
                carry = carry > 1 ? 1 : 0;
            }
            return ans;
        }
};
int main() {
    string a{"1010"};
    string b{"1011"};
    string k = Solution().addBinary(a, b);
    cout << k << endl;
    return 0;
};

/*
Given two binary strings a and b, return their sum as a binary string.
*/
/*
Constraints:
    1.  1 <= a.length, b.length <= 10^4
    2.  a and b consist only of '0' or '1' characters.
    3.  Each string does not contain leading zeros except for the zero itself.
*/