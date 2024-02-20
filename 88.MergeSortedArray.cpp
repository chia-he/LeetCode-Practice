/*
    1. Two Pointers
    Time Complexity: O(m+n), Space Complexity: O(1)
    3. Sorting
    Time Complexity: O((m+n)log(m+n)), Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int s1Index = m - 1;
        int s2Index = n - 1;
        int mergeIndex = m + n - 1;
        while(s2Index >= 0) {
            if (s1Index >= 0 && nums1[s1Index] > nums2[s2Index]) {
                nums1[mergeIndex--] = nums1[s1Index--];
            }
            else {
                nums1[mergeIndex--] = nums2[s2Index--];
            }
        }
    }
};
int main(void){
    vector<int> nums1{1,2,3,0,0,0};
    vector<int> nums2{2,5,6};
    Solution().merge(nums1, 3, nums2, 3);
    for(int n: nums1){
        cout << n << " ";
    }
    return 0;
};
/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/
/*
Constraints:
    1.  nums1.length == m + n
    2.  nums2.length == n
    3.  0 <= m, n <= 200
    4.  1 <= m + n <= 200
    5.  -10^9 <= nums1[i], nums2[i] <= 10^9
*/