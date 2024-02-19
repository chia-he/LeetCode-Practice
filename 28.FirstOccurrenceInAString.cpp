/*
    substr(int start, int length)
    Time: O((n-m+1)*m, Space: O(1)
    n is the length of haystack, m is the length of needle.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i = 0; i < haystack.size(); ++i){
            if(needle == haystack.substr(i, needle.size())) return i;
        }
        return -1;
    }
};
int main() {
    string haystack{"sadbutsad"}; 
    string needle{"sad"};
    int k = Solution().strStr(haystack, needle);

    cout << "Output: "<< k << endl;
    
    return 0;
};

/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/
/*
Constraints:
    1.  1 <= haystack.length, needle.length <= 10^4
    2.  haystack and needle consist of only lowercase English characters.
*/