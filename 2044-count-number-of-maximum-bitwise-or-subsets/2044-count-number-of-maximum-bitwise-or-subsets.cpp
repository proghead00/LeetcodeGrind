class Solution {
public:
	void help(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, int idx, int mx) {
		if (idx == nums.size()) {
            int orr = 0;
			for (auto pp : temp) {
				 orr = orr | pp;
			}

			if (orr == mx) ans.push_back(temp);
			return;
		}

		// pick
		temp.push_back(nums[idx]);
		help(nums, ans, temp, idx + 1, mx);

		// ignore
		temp.pop_back();
		help(nums, ans, temp, idx + 1, mx);
	}


	int countMaxOrSubsets(vector<int>& nums) {
		int mx = 0;
		for (auto x : nums) {
			mx = max(mx, x | mx);
		}

		vector<vector<int>> ans;
		vector<int> temp;

		help(nums, ans, temp, 0, mx);
		return ans.size();
	}
};