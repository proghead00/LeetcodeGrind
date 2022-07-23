class Solution {
public:

    vector<vector<int>> memo;
    
    int subsetsum(vector<int> &nums, int n, int target) {

        if (!n) {
            if (!target and nums[0] == 0) return 2; // when I have reached 0th pos, I can have 2 choices when 0 is present (pick or skip)

            else if (!target or target == nums[0]) return 1;
            else return 0;
        }

        if (memo[n][target] != -1)
            return memo[n][target];

        int nope = subsetsum(nums, n - 1, target);
        int yes = 0;
        if (nums[n] <= target) {
            yes = subsetsum(nums, n - 1, target - nums[n]);
        }

        return memo[n][target] = nope + yes;

    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int summ = accumulate(nums.begin(), nums.end(), 0);

        int diff = summ - target;
        if (diff & 1 or diff < 0) return 0;

        int tar = diff / 2;
        memo.resize(nums.size() + 10, vector<int>(tar + 10, -1));
        return subsetsum(nums, nums.size() - 1, tar);
    }
};