class Solution {
public:
    int help(vector<int> &nums, int target, int sum, int idx) {
        if (idx < 0) return target == sum;

        int plus = help(nums, target, sum + nums[idx], idx - 1);
        int minus = help(nums, target, sum - nums[idx], idx - 1);

        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return help(nums, target, 0, nums.size() - 1);
    }
};

