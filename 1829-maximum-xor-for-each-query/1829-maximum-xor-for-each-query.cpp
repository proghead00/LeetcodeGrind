class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> xors(n);

        xors[0] = nums[0];
        for (int i = 1; i < n; i++) {
            xors[i] = xors[i - 1] ^ nums[i];
        }

        int maxKPossible = (1 << maximumBit) - 1; // max possible value of k: 2 ^ maximumBit-1

        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) {
            int curK = maxKPossible & ~(xors[i]); // invert bits of (xors[i]) to maximize it
            ans.push_back(curK);
        }
        return ans;
    }
};