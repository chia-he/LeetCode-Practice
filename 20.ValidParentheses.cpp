/*
    Time: O(n), Space: O(n)
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            if (s.size() % 2 != 0) return false;
            stack<char> bracketsStack;
            for (char c : s) {
                if (c == '(' || c == '[' || c == '{') {
                    bracketsStack.push(c);
                } else {
                    if (bracketsStack.empty() ||
                        (c == ')' && bracketsStack.top() != '(') ||
                        (c == ']' && bracketsStack.top() != '[') ||
                        (c == '}' && bracketsStack.top() != '{')) {
                        return false;
                    }
                    bracketsStack.pop();
                }
            }
            return bracketsStack.empty();
        }
};
int main() {
    string s = {"()[]{}"};
    Solution solution;
    bool ans = solution.isValid(s);
    cout << "Output: " << ans << endl;
    return 0;
}

/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid. An input string is valid if:
    1.  Open brackets must be closed by the same type of brackets.
    2.  Open brackets must be closed in the correct order.
    3.  Every close bracket has a corresponding open bracket of the same type.
*/
/*
Constraints:
    1.  1 <= s.length <= 10^4
    2.  s consists of parentheses only '()[]{}'.
*/