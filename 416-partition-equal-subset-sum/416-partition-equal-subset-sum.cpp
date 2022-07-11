
class Solution {
public:

	bool help(vector<int> &nums, int target, int idx, vector<vector<int>> &dp) {

		if (target < 0) return false;
		
        // when target is reached
		if (!target) return true;

		// if the last element equals the target that I need
		if (idx == nums.size() - 1) return dp[idx][target] = (nums[nums.size() - 1] == target);

		if (target >= 0 and dp[idx][target] != -1) return dp[idx][target];

		bool dont = help(nums, target, idx + 1, dp);
		bool pick = help(nums, target - nums[idx], idx + 1, dp);

		return dp[idx][target] = pick or dont;
	}

	bool canPartition(vector<int>& nums) {
		int s = 0;
		for (int i = 0; i < nums.size(); i++) s += nums[i];

		// if the sum is odd, we can't divide it into 2 equal subsets
		if (s & 1) return false;

		vector<vector<int>> dp(nums.size() + 1, vector<int>(s / 2 + 1, -1));
		return help(nums, s / 2, 0, dp);
	}
};