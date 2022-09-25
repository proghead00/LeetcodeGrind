class Solution {
public :
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = size(nums), curSum = 0;
        int ans = 0, l = 0, r = 0;

        unordered_map<int, bool> mp;

        while (r < n) {
            while (mp[nums[r]]) {
                curSum -= nums[l]; mp[nums[l]] = false;
                l++;
            }

            curSum += nums[r];
            mp[nums[r++]] = true;
            ans = max(ans, curSum);
        }

        return ans;
    }
};