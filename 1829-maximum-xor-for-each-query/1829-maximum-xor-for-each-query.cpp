class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> xors(n);

        xors[0] = nums[0];
        for (int i = 1; i < n; i++) {
            xors[i] = xors[i - 1] ^ nums[i];
        }

        int idx = 0;
        int k = (1 << maximumBit) - 1; // (2^maximumBit-1)

        for (int i = n - 1; i >= 0; i--) {
            int curr = k & ~(xors[i]); // invert bits of (xors[i]) to maximize it
            nums[idx++] = curr;
        }
        return nums;
    }
};