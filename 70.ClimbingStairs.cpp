/*
    1. Recursive

    2. Iterative
    
    Time: O(nlogn), Space: O(1)
*/
#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1) return 1;
        else if(n == 2) return 2;
        int ans, cs1 = 1, cs2 = 2;
        for(int i = 3; i <= n; ++i){
            ans = cs1 + cs2;
            cs1 = cs2;
            cs2 = ans;
        }
        return ans;
    }
    int climbStairsRecursive(int n) {
        if(n == 0 || n == 1) return 1;
        else if(n == 2) return 2;
        else return climbStairsRecursive(n-1) + climbStairsRecursive(n-2);
    }
};
int main() {
    
    int ans;
    ans = Solution().climbStairs(4);
    cout << ans << " ";
    return 0;
}

/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
/*
Constraints:
    1.  1 <= n <= 45
*/