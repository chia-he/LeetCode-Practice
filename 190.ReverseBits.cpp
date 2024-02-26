/*
    Time Complexity: O(1), Space Complexity: O(1)
*/
using namespace std;
#include <iostream>
#include <cstdint>

class Solution {
public:
    uint32_t reverseBits_inplace(uint32_t n) {
        n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        
        return n;
    }
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++) {
            ans <<= 1;
            ans |= n & 1;
            n >>= 1;
        }
        return ans;
    }
};

int main(void){
    uint32_t n = 0b00000010100101000001111010011100;
    uint32_t ans = Solution().reverseBits_inplace(n);
    cout << ans << endl;
    return 0;
};

/*
Reverse bits of a given 32 bits unsigned integer.
*/
/*
Constraints:
    1. The input must be a binary string of length 32.
*/