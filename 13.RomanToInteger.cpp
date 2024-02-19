/*
    1. left to right
        Add all number. 
        If the next value is larger than the current value, do extra substract.
        EX: XIV = 10 + 1 + 5 - 2*1 = 14.
    2. right to left
        If the previous value is larger than the current value, do substract; otherwise, do plus.
        EX: XIV = 5 - 1 + 10 = 14.
    
    Time: O(n), Space: O(1)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMap{{'I', 1}, {'V', 5},
                                          {'X', 10}, {'L', 50},
                                          {'C', 100}, {'D', 500},
                                          {'M', 1000}};
        int previous = 0;
        int ans = 0;
        for(auto it=s.rbegin(); it<s.rend(); ++it ) {
            int current = romanMap[*it];
            if (current >= previous){
                ans += current;
            }
            else{
                ans -= current;
            }
            previous = current;
        }
        return ans;
    }
};
int main() {
    string s{"MCMXCIV"};
    Solution solution;
    int ans = solution.romanToInt(s);
    cout << "Output: " << ans << endl;
    return 0;
}

/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
Roman numerals are usually written largest to smallest from left to right. 
However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX.
There are six instances where subtraction is used:
    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.
*/
/*
Constraints:
    1.  1 <= s.length <= 15
    2.  s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
    3.  It is guaranteed that s is a valid roman numeral in the range [1, 3999].
*/