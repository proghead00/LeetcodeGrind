class Solution {
public:
    bool isPowerOfFour(int n) {
        // gotta 2 do checks:
        // 1. no. of set bits in n should be equal to 1 (pwoer of 2 concept)
        // 2. the bit that is set, should be in the even position (based on lop variable i here)

        if (__builtin_popcount(n) > 1) return false;

        int cnt = 0;
        for (int i = 0; i < 32; i++) {
            if (((n >> i) & 1) and (i % 2 == 0)) {
                cnt++;
                if (cnt > 1) return false;
            }
        }
        return (cnt == 1) ? true : false;
    }
};