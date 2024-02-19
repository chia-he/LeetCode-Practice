/*
    1.  Brute Force
        All strings have common prefix, do a for loop to compare characters with one of the string, if any of the characters is different or length not same, done.
        Time: O(n*m), Space: O(1);
        m is the length of the common prefix.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for(int i=0; i<strs[0].size(); ++i){
            char referenceChar = strs[0][i];
            for (int j=1; j<strs.size(); ++j){
                if(strs[j].size()<i || strs[j][i]!=referenceChar) 
                    return ans;
            }
            ans += referenceChar;
        }
        return ans;
    }
};
int main() {
    vector<string> s{"flower","flow","flight"};
    Solution solution;
    string ans = solution.longestCommonPrefix(s);
    cout << "Output: " << ans << endl;
    return 0;
}

/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
*/
/*
Constraints:
    1.  1 <= strs.length <= 200
    2.  0 <= strs[i].length <= 200
    3.  strs[i] consists of only lowercase English letters.
*/